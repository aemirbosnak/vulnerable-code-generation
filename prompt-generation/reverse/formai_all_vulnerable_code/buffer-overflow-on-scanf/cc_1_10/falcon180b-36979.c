//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

struct entry {
    char name[50];
    char phone[20];
};

void add_entry(struct entry entries[], int count) {
    char name[50], phone[20];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter phone number: ");
    scanf("%s", phone);

    strcpy(entries[count].name, name);
    strcpy(entries[count].phone, phone);

    count++;
}

void search_entry(struct entry entries[], int count, char search_name[]) {
    int i;

    for(i=0; i<count; i++) {
        if(strcmp(entries[i].name, search_name) == 0) {
            printf("Name: %s\nPhone number: %s\n", entries[i].name, entries[i].phone);
        }
    }
}

void delete_entry(struct entry entries[], int count, char delete_name[]) {
    int i;

    for(i=0; i<count; i++) {
        if(strcmp(entries[i].name, delete_name) == 0) {
            memmove(&entries[i], &entries[i+1], (count-i-1)*sizeof(struct entry));
            count--;
            break;
        }
    }
}

void display_entries(struct entry entries[], int count) {
    int i;

    for(i=0; i<count; i++) {
        printf("Name: %s\nPhone number: %s\n", entries[i].name, entries[i].phone);
    }
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int count = 0;

    while(1) {
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Display all entries\n5. Exit\n");
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
                printf("Enter name to search: ");
                char search_name[50];
                scanf("%s", search_name);
                search_entry(entries, count, search_name);
                break;
            case 3:
                printf("Enter name to delete: ");
                char delete_name[50];
                scanf("%s", delete_name);
                delete_entry(entries, count, delete_name);
                break;
            case 4:
                display_entries(entries, count);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}