//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_REC 100

struct record {
    char name[50];
    char address[100];
    char phone[20];
};

void add_record(struct record *db, int *num_recs) {
    char name[50], address[100], phone[20];
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter address: ");
    scanf("%s", address);
    printf("Enter phone number: ");
    scanf("%s", phone);

    strcpy(db[*num_recs].name, name);
    strcpy(db[*num_recs].address, address);
    strcpy(db[*num_recs].phone, phone);

    (*num_recs)++;
}

void search_record(struct record *db, int num_recs, char *key) {
    int i;

    for (i = 0; i < num_recs; i++) {
        if (strcmp(db[i].name, key) == 0) {
            printf("Name: %s\n", db[i].name);
            printf("Address: %s\n", db[i].address);
            printf("Phone number: %s\n", db[i].phone);
            return;
        }
    }

    printf("Record not found.\n");
}

void delete_record(struct record *db, int *num_recs) {
    char name[50];
    int i, j;

    printf("Enter name to delete: ");
    scanf("%s", name);

    for (i = 0; i < *num_recs; i++) {
        if (strcmp(db[i].name, name) == 0) {
            for (j = i; j < *num_recs - 1; j++) {
                strcpy(db[j].name, db[j + 1].name);
                strcpy(db[j].address, db[j + 1].address);
                strcpy(db[j].phone, db[j + 1].phone);
            }
            (*num_recs)--;
            return;
        }
    }

    printf("Record not found.\n");
}

int main() {
    struct record db[MAX_REC];
    int num_recs = 0;

    while (1) {
        printf("\n1. Add record\n2. Search record\n3. Delete record\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_recs >= MAX_REC) {
                printf("Database is full.\n");
            } else {
                add_record(db, &num_recs);
            }
            break;

        case 2:
            printf("Enter name to search: ");
            char key[50];
            scanf("%s", key);
            search_record(db, num_recs, key);
            break;

        case 3:
            if (num_recs == 0) {
                printf("Database is empty.\n");
            } else {
                delete_record(db, &num_recs);
            }
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}