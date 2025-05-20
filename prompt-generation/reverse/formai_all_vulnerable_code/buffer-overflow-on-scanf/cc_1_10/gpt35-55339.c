//FormAI DATASET v1.0 Category: Database Indexing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_PHONE_LENGTH 20

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} record;

typedef struct {
    int id;
    int offset;
} index_record;

typedef struct {
    index_record index[MAX_RECORDS];
    int count;
} index_table;

int binary_search(index_table table, int id){
    int left = 0;
    int right = table.count - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(table.index[mid].id == id)
            return table.index[mid].offset;
        else if (table.index[mid].id < id)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void populate_index_table(FILE* fp, index_table* table){
    fseek(fp, 0, SEEK_SET);
    int offset = 0;
    while(!feof(fp)){
        record r;
        fread(&r, sizeof(record), 1, fp);
        if(feof(fp))
            break;
        index_record ir;
        ir.id = r.id;
        ir.offset = offset;
        table->index[table->count++] = ir;        
        offset = ftell(fp);
    }
}

void create_index(char* file_name){
    FILE* fp = fopen(file_name, "r+b");
    index_table table = {0};
    populate_index_table(fp, &table);
    if(table.count > 0){
        fseek(fp, 0, SEEK_END);
        int end_of_file = ftell(fp);
        fwrite(&table, sizeof(index_table), 1, fp);
        fseek(fp, end_of_file, SEEK_SET);
    }
    fclose(fp);
}

record read_record(){
    record r;
    printf("Enter ID: ");
    scanf("%d", &r.id);
    fflush(stdin);
    printf("Enter Name: ");
    fgets(r.name, MAX_NAME_LENGTH, stdin);
    r.name[strcspn(r.name, "\n")] = 0;
    printf("Enter Address: ");
    fgets(r.address, MAX_ADDRESS_LENGTH, stdin);
    r.address[strcspn(r.address, "\n")] = 0;
    printf("Enter Phone: ");
    fgets(r.phone, MAX_PHONE_LENGTH, stdin);
    r.phone[strcspn(r.phone, "\n")] = 0;
    return r;
}

void add_record(char* file_name){
    FILE* fp = fopen(file_name, "a+b");
    fseek(fp, 0, SEEK_END);
    record r = read_record();
    fwrite(&r, sizeof(record), 1, fp);
    fclose(fp);
}

void search_record(char* file_name){
    FILE* fp = fopen(file_name, "r+b");
    index_table table;
    fread(&table, sizeof(index_table), 1, fp);
    int id;
    printf("Enter ID to Search: ");
    scanf("%d", &id);
    fflush(stdin);
    int offset = binary_search(table, id);
    if(offset != -1){
        record r;
        fseek(fp, offset, SEEK_SET);
        fread(&r, sizeof(record), 1, fp);
        printf("Record Found:\n");
        printf("ID: %d\n", r.id);
        printf("Name: %s\n", r.name);
        printf("Address: %s\n", r.address);
        printf("Phone: %s\n", r.phone);
    }
    else{
        printf("Record Not Found!\n");
    }
    fclose(fp);
}

int main(){
    printf("Welcome to Futuristic Database Indexing System!\n");
    printf("1. Create Index\n");
    printf("2. Add Record\n");
    printf("3. Search Record\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    if(choice == 1){
        printf("Enter File Name: ");
        char file_name[MAX_NAME_LENGTH];
        fflush(stdin);
        fgets(file_name, MAX_NAME_LENGTH, stdin);
        file_name[strcspn(file_name, "\n")] = 0;
        create_index(file_name);
        printf("Index Created Successfully!\n");
    }
    else if(choice == 2){
        printf("Enter File Name: ");
        char file_name[MAX_NAME_LENGTH];
        fflush(stdin);
        fgets(file_name, MAX_NAME_LENGTH, stdin);
        file_name[strcspn(file_name, "\n")] = 0;
        add_record(file_name);
        printf("Record Added Successfully!\n");
    }
    else if(choice == 3){
        printf("Enter File Name: ");
        char file_name[MAX_NAME_LENGTH];
        fflush(stdin);
        fgets(file_name, MAX_NAME_LENGTH, stdin);
        file_name[strcspn(file_name, "\n")] = 0;
        search_record(file_name);
    }
    else{
        printf("Invalid Choice!\n");
    }
    return 0;
}