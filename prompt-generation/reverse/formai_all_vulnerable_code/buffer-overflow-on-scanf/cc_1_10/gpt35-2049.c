//FormAI DATASET v1.0 Category: Database Indexing System ; Style: complex
#include<stdio.h>
#include<string.h>
#define MAX 100

typedef struct student {       //structure of a student record
    int id;            
    char name[MAX];
    float cgpa;
} student;

typedef struct index_node {
    int key;
    long offset;
} index_node;                //structure for index record

void insert(int key, long offset, FILE *index_file) {
    index_node node;
    node.key = key;
    node.offset = offset;
    
    fseek(index_file, 0, SEEK_SET);
    int current_size = 0;
    fread(&current_size, sizeof(int), 1, index_file);
    
    if(current_size == 0) {
        fseek(index_file, sizeof(int), SEEK_SET);
        fwrite(&node, sizeof(index_node), 1, index_file);
        current_size++;
        fseek(index_file, 0, SEEK_SET);
        fwrite(&current_size, sizeof(int), 1, index_file);
    }
    else {
        index_node* nodes = (index_node*) malloc(sizeof(index_node) * current_size);
        fread(nodes, sizeof(index_node), current_size, index_file);
        int i = 0;
        while(i < current_size && nodes[i].key < key) i++;
        if(i == current_size) {
            fseek(index_file, -sizeof(index_node), SEEK_END);
            fwrite(&node, sizeof(index_node), 1, index_file);
        }
        else {
            fseek(index_file, 0, SEEK_SET);
            fseek(index_file, (i * sizeof(index_node)) + sizeof(int), SEEK_SET);
            int remaining_size = current_size - i;
            index_node* temp = (index_node*) malloc(sizeof(index_node) * remaining_size);
            fread(temp, sizeof(index_node), remaining_size, index_file);
            fseek(index_file, -sizeof(index_node), SEEK_CUR);
            fwrite(&node, sizeof(index_node), 1, index_file);
            fwrite(temp, sizeof(index_node), remaining_size, index_file);
            free(temp);
        }
        current_size++;
        fseek(index_file, 0, SEEK_SET);
        fwrite(&current_size, sizeof(int), 1, index_file);
        free(nodes);
    }
}

void search(int key, FILE *index_file, FILE *data_file) {
    int current_size = 0;
    fseek(index_file, 0, SEEK_SET);
    fread(&current_size, sizeof(int), 1, index_file);
    if(current_size == 0) {
        printf("Index file is empty!\n");
        return;
    }
    else {
        index_node* nodes = (index_node*) malloc(sizeof(index_node) * current_size);
        fread(nodes, sizeof(index_node), current_size, index_file);
        int left = 0;
        int right = current_size - 1;
        int mid = (left + right) / 2;
        while(left <= right) {
            if(nodes[mid].key == key) {
                fseek(data_file, nodes[mid].offset, SEEK_SET);
                student s;
                fread(&s, sizeof(student), 1, data_file);
                printf("Record found: id=%d name=%s cgpa=%.2f\n", s.id, s.name, s.cgpa);
                free(nodes);
                return;
            }
            else if(nodes[mid].key < key) {
                left = mid + 1;
                mid = (left + right) / 2;
            }
            else {
                right = mid - 1;
                mid = (left + right) / 2;
            }
        }
        printf("Record not found!\n");
        free(nodes);
        return;
    }
}

int main() {
    FILE *data_file = fopen("data.dat", "wb");
    FILE *index_file = fopen("index.dat", "wb");
    int n;
    printf("Enter number of records: ");
    scanf("%d", &n);
    student* records = (student*) malloc(sizeof(student) * n);
    for(int i = 0; i < n; i++) {
        student s;
        printf("Enter id, name, and cgpa separated by spaces for record #%d: ", i+1);
        scanf("%d %s %f", &s.id, s.name, &s.cgpa);
        fwrite(&s, sizeof(student), 1, data_file);
        insert(s.id, ftell(data_file) - sizeof(student), index_file);
    }
    printf("Enter id to search for: ");
    int id;
    scanf("%d", &id);
    search(id, index_file, data_file);
    fclose(data_file);
    fclose(index_file);
    free(records);
    return 0;
}