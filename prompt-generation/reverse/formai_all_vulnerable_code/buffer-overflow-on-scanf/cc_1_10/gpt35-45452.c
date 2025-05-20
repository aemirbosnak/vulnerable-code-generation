//FormAI DATASET v1.0 Category: Database simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLUMNS 100
#define MAX_DATABASES 10

/*
 * Database simulation example with a puzzling twist
 */

struct Database {
    char name[20];
    int rows;
    int columns;
    int data[MAX_ROWS][MAX_COLUMNS];
};

struct Database databases[MAX_DATABASES];
int num_databases = 0;

void create_database(char* name, int rows, int columns) {
    int i, j;
    strcpy(databases[num_databases].name, name);
    databases[num_databases].rows = rows;
    databases[num_databases].columns = columns;
    for(i=0;i<rows;i++) {
        for(j=0;j<columns;j++) {
            databases[num_databases].data[i][j] = rand() % 100;
        }
    }
    num_databases++;
}

void print_database(char* name) {
    int i, j;
    int found = 0;
    for(i=0;i<num_databases;i++) {
        if(strcmp(databases[i].name, name) == 0) {
            found = 1;
            printf("Printing database %s\n", name);
            for(i=0;i<databases[i].rows;i++) {
                for(j=0;j<databases[i].columns;j++) {
                    printf("%d ", databases[i].data[i][j]);
                }
                printf("\n");
            }
        }
    }
    if(!found) {
        printf("Database %s not found\n", name);
    }
}

void delete_database(char* name) {
    int i;
    int found = 0;
    for(i=0;i<num_databases;i++) {
        if(strcmp(databases[i].name, name) == 0) {
            found = 1;
            printf("Deleting database %s\n", name);
            memmove(&databases[i], &databases[i+1], (num_databases - i - 1) * sizeof(struct Database));
            num_databases--;
            break;
        }
    }
    if(!found) {
        printf("Database %s not found\n", name);
    }
}

int main() {
    int choice;
    char name[20];
    int rows, columns;
    srand(time(0));
    printf("Welcome to the database simulation program\n");
    do {
        printf("Enter your choice:\n");
        printf("1. Create database\n");
        printf("2. Print database\n");
        printf("3. Delete database\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter database name:\n");
                scanf("%s", name);
                printf("Enter number of rows:\n");
                scanf("%d", &rows);
                printf("Enter number of columns:\n");
                scanf("%d", &columns);
                create_database(name, rows, columns);
                printf("Database %s created\n", name);
                break;
            case 2:
                printf("Enter database name:\n");
                scanf("%s", name);
                print_database(name);
                break;
            case 3:
                printf("Enter database name:\n");
                scanf("%s", name);
                delete_database(name);
                break;
            case 4:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while(choice != 4);
    return 0;
}