//FormAI DATASET v1.0 Category: Database Indexing System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    int id;
    char name[100];
    int age;
};

struct index {
    int id;
    int offset;
};

int main() {
    struct person p;
    struct index index[100];
    int i = 0, j = 0, k = 0;
    FILE *fp, *ip;
    char name[100], c;

    fp = fopen("data.txt", "w");

    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    
    while(1) {
        printf("Enter ID: ");
        scanf("%d", &p.id);
        printf("Enter name: ");
        scanf("%s", p.name);
        printf("Enter age: ");
        scanf("%d", &p.age);

        fwrite(&p, sizeof(struct person), 1, fp);
        
        index[i].id = p.id;
        index[i].offset = ftell(fp) - sizeof(struct person);
        i++;

        printf("Enter more records? (y/n): ");
        scanf(" %c", &c);

        if(c != 'y')
            break;
    }

    fclose(fp);

    ip = fopen("index.txt", "w");

    if(ip == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    for(j = 0; j < i; j++) {
        for(k = j + 1; k < i; k++) {
            if(index[j].id > index[k].id) {
                int temp = index[j].id;
                index[j].id = index[k].id;
                index[k].id = temp;

                temp = index[j].offset;
                index[j].offset = index[k].offset;
                index[k].offset = temp;
            }
        }

        fprintf(ip, "%d %d\n", index[j].id, index[j].offset);
    }

    fclose(ip);

    printf("Enter ID to search: ");
    scanf("%d", &i);

    ip = fopen("index.txt", "r");

    if(ip == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while(fscanf(ip, "%d %d", &j, &k) != EOF) {
        if(j == i) {
            fp = fopen("data.txt", "r");
            fseek(fp, k, SEEK_SET);
            fread(&p, sizeof(struct person), 1, fp);
            printf("ID: %d, Name: %s, Age: %d\n", p.id, p.name, p.age);
            fclose(fp);
            break;
        }
    }

    fclose(ip);

    return 0;
}