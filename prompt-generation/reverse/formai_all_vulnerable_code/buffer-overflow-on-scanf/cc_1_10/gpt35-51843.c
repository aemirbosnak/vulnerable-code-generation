//FormAI DATASET v1.0 Category: Phone Book ; Style: real-life
#include <stdio.h>
#include <string.h>

struct contact {
    char name[50];
    char phone[20];
};

struct contact_list {
    struct contact entries[100];
    int num_entries;
};

void add_contact(struct contact_list *cl, char *name, char *phone) {
    if (cl->num_entries < 100) {
        strcpy(cl->entries[cl->num_entries].name, name);
        strcpy(cl->entries[cl->num_entries].phone, phone);
        cl->num_entries++;
        printf("Contact added successfully!\n");
    } else {
        printf("Contact list is full!\n");
    }
}

void remove_contact(struct contact_list *cl, char *name) {
    int i;
    for (i = 0; i < cl->num_entries; i++) {
        if (strcmp(cl->entries[i].name, name) == 0) {
            int j;
            for (j = i; j < cl->num_entries-1; j++) {
                strcpy(cl->entries[j].name, cl->entries[j+1].name);
                strcpy(cl->entries[j].phone, cl->entries[j+1].phone);
            }
            cl->num_entries--;
            printf("Contact removed successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

void search_contact(struct contact_list *cl, char *name) {
    int i;
    for (i = 0; i < cl->num_entries; i++) {
        if (strcmp(cl->entries[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", cl->entries[i].name, cl->entries[i].phone);
            return;
        }
    }
    printf("Contact not found!\n");
}

void display_contacts(struct contact_list *cl) {
    int i;
    for (i = 0; i < cl->num_entries; i++) {
        printf("%d. Name: %s, Phone: %s\n", i+1, cl->entries[i].name, cl->entries[i].phone);
    }
}

int main() {
    struct contact_list cl = {0};
    int option;
    do {
        printf("1. Add contact\n2. Remove contact\n3. Search contact\n4. Display all contacts\n5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                {
                    char name[50], phone[20];
                    printf("Enter name: ");
                    scanf("%s", name);
                    printf("Enter phone: ");
                    scanf("%s", phone);
                    add_contact(&cl, name, phone);
                    break;
                }

            case 2:
                {
                    char name[50];
                    printf("Enter name: ");
                    scanf("%s", name);
                    remove_contact(&cl, name);
                    break;
                }

            case 3:
                {
                    char name[50];
                    printf("Enter name: ");
                    scanf("%s", name);
                    search_contact(&cl, name);
                    break;
                }

            case 4:
                {
                    display_contacts(&cl);
                    break;
                }

            case 5:
                {
                    printf("Exiting program...\n");
                    break;
                }

            default:
                {
                    printf("Invalid option!\n");
                }
        }
    } while (option != 5);
    return 0;
}