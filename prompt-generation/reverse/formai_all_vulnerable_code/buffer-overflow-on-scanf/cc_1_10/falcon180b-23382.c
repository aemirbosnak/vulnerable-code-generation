//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: multivariable
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

void display_entry(struct entry entry) {
    printf("Name: %s\n", entry.name);
    printf("Phone: %s\n", entry.phone);
}

void search_entry(struct entry entries[], int count, char name[]) {
    int i;
    for(i = 0; i < count; i++) {
        if(strcmp(entries[i].name, name) == 0) {
            display_entry(entries[i]);
            return;
        }
    }
    printf("Entry not found.\n");
}

void delete_entry(struct entry entries[], int count, char name[]) {
    int i;
    for(i = 0; i < count; i++) {
        if(strcmp(entries[i].name, name) == 0) {
            memmove(&entries[i], &entries[i+1], (count-i-1)*sizeof(struct entry));
            count--;
            return;
        }
    }
    printf("Entry not found.\n");
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int count = 0;

    printf("Phone Book\n");
    while(1) {
        printf("1. Add entry\n");
        printf("2. Display entry\n");
        printf("3. Search entry\n");
        printf("4. Delete entry\n");
        printf("5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(count >= MAX_ENTRIES) {
                    printf("Maximum entries reached.\n");
                } else {
                    add_entry(entries, count);
                    count++;
                }
                break;
            case 2:
                printf("Enter name to display: ");
                char name[50];
                scanf("%s", name);
                search_entry(entries, count, name);
                break;
            case 3:
                printf("Enter name to search: ");
                char name2[50];
                scanf("%s", name2);
                search_entry(entries, count, name2);
                break;
            case 4:
                printf("Enter name to delete: ");
                char name3[50];
                scanf("%s", name3);
                delete_entry(entries, count, name3);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}