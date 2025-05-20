//FormAI DATASET v1.0 Category: Database simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

struct student {
    int id;
    char name[50];
    int marks;
};

void add_student(struct student records[], int *num_records);
void print_record(struct student record);
void print_all_records(struct student records[], int num_records);
void save_records(struct student records[], int num_records);
int load_records(struct student records[]);

int main()
{
    struct student records[MAX_RECORDS];
    int num_records = 0;

    num_records = load_records(records);

    char option;
    do {
        printf("\n1. Add new student record\n");
        printf("2. Print a specific record\n");
        printf("3. Print all records\n");
        printf("4. Save records\n");
        printf("5. Exit\n");

        printf("\nEnter option: ");
        scanf(" %c", &option);

        switch(option) {
            case '1':
                add_student(records, &num_records);
                break;

            case '2':
                if(num_records) {
                    int id;
                    printf("\nEnter student ID: ");
                    scanf("%d", &id);

                    int found = 0;
                    for(int i=0; i<num_records; i++) {
                        if(records[i].id == id) {
                            print_record(records[i]);
                            found = 1;
                            break;
                        }
                    }
                    if(!found) printf("\nStudent record not found.");

                } else {
                    printf("\nNo records found.");
                }
                break;

            case '3':
                if(num_records) {
                    printf("\nStudent Records - \n");
                    print_all_records(records, num_records);
                } else {
                    printf("\nNo records found.");
                }
                break;

            case '4':
                if(num_records) {
                    save_records(records, num_records);
                    printf("\nRecords saved successfully!");
                } else {
                    printf("\nNo records found.");
                }
                break;

            case '5':
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid option.");
                break;
        }

    } while(option != '5');

    return 0;
}

void add_student(struct student records[], int *num_records) {
    if((*num_records) == MAX_RECORDS) {
        printf("\nMaximum number of records reached.");
        return;
    }

    struct student s;
    s.id = (*num_records) + 1;

    printf("\nEnter student name: ");
    scanf("%s", s.name);

    printf("Enter student marks: ");
    scanf("%d", &s.marks);

    records[(*num_records)] = s;
    (*num_records)++;

    printf("\nRecord added successfully.");
}

void print_record(struct student record) {
    printf("\nID: %d", record.id);
    printf("\nName: %s", record.name);
    printf("\nMarks: %d\n", record.marks);
}

void print_all_records(struct student records[], int num_records) {
    for(int i=0; i<num_records; i++) {
        print_record(records[i]);
    }
}

void save_records(struct student records[], int num_records) {
    FILE *fp;
    fp = fopen("students.db", "wb");
    fwrite(records, sizeof(struct student), num_records, fp);
    fclose(fp);
}

int load_records(struct student records[]) {
    FILE *fp;
    fp = fopen("students.db", "rb");
    if(fp == NULL) {
        return 0;
    }

    int num_records = 0;
    while(fread(&records[num_records], sizeof(struct student), 1, fp)) {
        num_records++;
    }

    fclose(fp);
    return num_records;
}