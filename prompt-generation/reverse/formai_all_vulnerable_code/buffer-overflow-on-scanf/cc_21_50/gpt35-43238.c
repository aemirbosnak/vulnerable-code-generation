//FormAI DATASET v1.0 Category: Database simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

struct record {
    int id;
    char name[50];
    float score;
};

int main() {
    int choice, i, j, id;
    struct record db[MAX_RECORDS];
    int num_records = 0;
    float score;
    char name[50];
    
    printf("Welcome to the Database\n");

    do {
        printf("\n1. Add record\n");
        printf("2. Display record\n");
        printf("3. Update record\n");
        printf("4. Delete record\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_records == MAX_RECORDS) {
                    printf("Error: Database is full\n");
                } else {
                    printf("Enter id: ");
                    scanf("%d", &id);
                    for (i = 0; i < num_records; i++) {
                        if (db[i].id == id) {
                            printf("Error: Record with id %d already exists\n", id);
                            break;
                        }
                    }
                    if (i == num_records) {
                        db[num_records].id = id;
                        printf("Enter name: ");
                        scanf("%s", name);
                        strcpy(db[num_records].name, name);
                        printf("Enter score: ");
                        scanf("%f", &score);
                        db[num_records].score = score;
                        num_records++;
                        printf("Record added successfully\n");
                    }
                }
                break;
            case 2:
                if (num_records == 0) {
                    printf("Error: Database is empty\n");
                } else {
                    printf("Id\tName\tScore\n");
                    for (i = 0; i < num_records; i++) {
                        printf("%d\t%s\t%.2f\n", db[i].id, db[i].name, db[i].score);
                    }               
                }
                break;
            case 3:
                if (num_records == 0) {
                    printf("Error: Database is empty\n");
                } else {
                    printf("Enter id: ");
                    scanf("%d", &id);
                    for (i = 0; i < num_records; i++) {
                        if (db[i].id == id) {
                            printf("Enter name: ");
                            scanf("%s", name);
                            strcpy(db[i].name, name);
                            printf("Enter score: ");
                            scanf("%f", &score);
                            db[i].score = score;
                            printf("Record updated successfully\n");
                            break;
                        }
                    }
                    if (i == num_records) {
                        printf("Error: Record with id %d not found\n", id);
                    }
                }
                break;
            case 4:
                if (num_records == 0) {
                    printf("Error: Database is empty\n");
                } else {
                    printf("Enter id: ");
                    scanf("%d", &id);
                    for (i = 0; i < num_records; i++) {
                        if (db[i].id == id) {
                            for (j = i; j < num_records - 1; j++) {
                                db[j] = db[j+1];
                            }
                            num_records--;
                            printf("Record deleted successfully\n");
                            break;
                        }
                    }
                    if (i == num_records) {
                        printf("Error: Record with id %d not found\n", id);
                    }
                }
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Error: Invalid choice\n");
                break;
        }
    } while (choice != 5);

    return 0;
}