//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct entry {
    char name[50];
    char phone[15];
};

void add_entry(struct entry entries[], int count) {
    printf("Enter name: ");
    scanf("%s", entries[count].name);
    printf("Enter phone number: ");
    scanf("%s", entries[count].phone);
    count++;
}

void search_entry(struct entry entries[], int count, char name[]) {
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Phone number for %s is %s\n", entries[i].name, entries[i].phone);
            return;
        }
    }
    printf("No entry found for %s\n", name);
}

void delete_entry(struct entry entries[], int count, char name[]) {
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            memmove(&entries[i], &entries[i+1], (count-i-1)*sizeof(struct entry));
            count--;
            break;
        }
    }
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int count = 0;

    printf("Phone Book\n");
    while (1) {
        printf("\n1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count >= MAX_ENTRIES) {
                    printf("Phone book is full\n");
                    break;
                }
                add_entry(entries, count);
                count++;
                break;
            case 2:
                printf("Enter name to search: ");
                char name[50];
                scanf("%s", name);
                search_entry(entries, count, name);
                break;
            case 3:
                printf("Enter name to delete: ");
                char del_name[50];
                scanf("%s", del_name);
                delete_entry(entries, count, del_name);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}