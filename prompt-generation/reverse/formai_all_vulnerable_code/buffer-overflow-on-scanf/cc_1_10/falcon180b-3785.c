//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: cheerful
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX 100

struct phonebook {
    char name[MAX];
    int phone[MAX];
    int count;
};

struct phonebook create_phonebook() {
    struct phonebook pb;
    pb.count = 0;
    return pb;
}

void add_contact(struct phonebook* pb, char* name, int phone) {
    strcpy(pb->name[pb->count], name);
    pb->phone[pb->count] = phone;
    pb->count++;
}

void display_phonebook(struct phonebook pb) {
    printf("\n\nPhonebook:\n");
    for(int i=0;i<pb.count;i++) {
        printf("\nName: %s\nPhone: %d\n", pb.name[i], pb.phone[i]);
    }
}

void delete_contact(struct phonebook* pb, char* name) {
    int j;
    for(int i=0;i<pb->count;i++) {
        if(strcmp(pb->name[i], name) == 0) {
            for(j=i;j<pb->count-1;j++) {
                strcpy(pb->name[j], pb->name[j+1]);
                pb->phone[j] = pb->phone[j+1];
            }
            pb->count--;
            break;
        }
    }
}

int search_contact(struct phonebook pb, char* name) {
    int i;
    for(i=0;i<pb.count;i++) {
        if(strcmp(pb.name[i], name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    struct phonebook pb = create_phonebook();
    int choice;
    do {
        printf("\n\n1. Add Contact\n2. Display Phonebook\n3. Search Contact\n4. Delete Contact\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                char name[MAX];
                int phone;
                printf("\nEnter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%d", &phone);
                add_contact(&pb, name, phone);
                printf("\nContact added successfully!\n");
                break;
            }
            case 2: {
                display_phonebook(pb);
                break;
            }
            case 3: {
                char name[MAX];
                int index = search_contact(pb, name);
                if(index!= -1) {
                    printf("\nName: %s\nPhone: %d\n", pb.name[index], pb.phone[index]);
                } else {
                    printf("\nContact not found!\n");
                }
                break;
            }
            case 4: {
                char name[MAX];
                int index = search_contact(pb, name);
                if(index!= -1) {
                    delete_contact(&pb, name);
                    printf("\nContact deleted successfully!\n");
                } else {
                    printf("\nContact not found!\n");
                }
                break;
            }
            case 5: {
                printf("\nExiting program...\n");
            }
            default: {
                printf("\nInvalid choice!\n");
            }
        }
    } while(choice!= 5);
    return 0;
}