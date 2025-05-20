//FormAI DATASET v1.0 Category: Mailing list manager ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100
#define MAX_LIST_SIZE 100

struct contact {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
};

struct contact_list {
    struct contact contacts[MAX_LIST_SIZE];
    int size;
};

void display_menu() {
    printf("\n");
    printf("Mailing List Manager\n");
    printf("====================\n");
    printf("1. Add contact\n");
    printf("2. View contacts\n");
    printf("3. Remove contact\n");
    printf("4. Save to file\n");
    printf("5. Load from file\n");
    printf("6. Quit\n");
    printf("\n");
}

void add_contact(struct contact_list *list) {
    struct contact new_contact;
    printf("Enter name: ");
    scanf("%s", new_contact.name);
    printf("Enter email: ");
    scanf("%s", new_contact.email);
    list->contacts[list->size] = new_contact;
    list->size++;
    printf("\nContact added!\n");
}

void view_contacts(struct contact_list *list) {
    printf("\nContacts:\n");
    for (int i = 0; i < list->size; i++) {
        printf("%s - %s\n", list->contacts[i].name, list->contacts[i].email);
    }
}

void remove_contact(struct contact_list *list) {
    char name_to_remove[MAX_NAME_LEN];
    printf("Enter name of contact to remove: ");
    scanf("%s", name_to_remove);
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->contacts[i].name, name_to_remove) == 0) {
            for (int j = i; j < list->size - 1; j++) {
                list->contacts[j] = list->contacts[j+1];
            }
            list->size--;
            printf("\nContact removed!\n");
            return;
        }
    }
    printf("\nContact not found!\n");
}

void save_to_file(struct contact_list *list) {
    FILE *file = fopen("mailing_list.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < list->size; i++) {
        fprintf(file, "%s,%s\n", list->contacts[i].name, list->contacts[i].email);
    }
    fclose(file);
    printf("\nFile saved!\n");
}

void load_from_file(struct contact_list *list) {
    FILE *file = fopen("mailing_list.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    char line[MAX_NAME_LEN + MAX_EMAIL_LEN + 2];
    while (fgets(line, MAX_NAME_LEN + MAX_EMAIL_LEN + 2, file) != NULL) {
        char *name = strtok(line, ",");
        char *email = strtok(NULL, ",");
        struct contact loaded_contact;
        strcpy(loaded_contact.name, name);
        strcpy(loaded_contact.email, email);
        list->contacts[list->size] = loaded_contact;
        list->size++;
    }
    fclose(file);
    printf("\nFile loaded!\n");
}

int main() {
    struct contact_list list;
    list.size = 0;
    int choice = 0;
    while (choice != 6) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_contact(&list);
                break;
            case 2:
                view_contacts(&list);
                break;
            case 3:
                remove_contact(&list);
                break;
            case 4:
                save_to_file(&list);
                break;
            case 5:
                load_from_file(&list);
                break;
            case 6:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}