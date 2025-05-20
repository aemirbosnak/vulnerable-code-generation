//FormAI DATASET v1.0 Category: File handling ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
    char name[50];
    int age;
    float salary;
};

int main() {
    struct record r;
    char filename[50];
    printf("Enter file name to create: ");
    scanf("%s", filename);
    FILE *fp = fopen(filename, "w+");
    if(fp == NULL) {
        printf("Error creating file.\n");
        exit(1);
    }
    int choice;
    do {
        printf("\n1. Add record\n2. Search record\n3. Display all records\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                printf("Enter name: ");
                scanf("%s", r.name);
                printf("Enter age: ");
                scanf("%d", &r.age);
                printf("Enter salary: ");
                scanf("%f", &r.salary);
                fwrite(&r, sizeof(struct record), 1, fp);
                printf("Record added successfully.\n");
                break;
            }
            case 2: {
                char search_name[50];
                printf("Enter name to search: ");
                scanf("%s", search_name);
                int found = 0;
                while(fread(&r, sizeof(struct record), 1, fp)) {
                    if(strcmp(r.name, search_name) == 0) {
                        printf("Record found:\n");
                        printf("Name: %s\nAge: %d\nSalary: %f\n", r.name, r.age, r.salary);
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    printf("No record found with name %s.\n", search_name);
                }
                break;
            }
            case 3: {
                rewind(fp);
                while(fread(&r, sizeof(struct record), 1, fp)) {
                    printf("Name: %s\nAge: %d\nSalary: %f\n", r.name, r.age, r.salary);
                }
                break;
            }
            case 4: {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
    } while(choice != 4);
    fclose(fp);
    return 0;
}