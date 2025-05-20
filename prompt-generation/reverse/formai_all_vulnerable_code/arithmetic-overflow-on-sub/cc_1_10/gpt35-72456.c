//FormAI DATASET v1.0 Category: Mailing list manager ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LEN 50
#define MAX_NAME_LEN 50
#define MAX_PEOPLE 100

struct person {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
};

struct mailing_list {
    struct person people[MAX_PEOPLE];
    int num_people;
};

void add_person(struct mailing_list* list, char* name, char* email) {
    if (list->num_people == MAX_PEOPLE) {
        printf("The mailing list is full!\n");
        return;
    }
    
    struct person new_person;
    strncpy(new_person.name, name, MAX_NAME_LEN);
    new_person.name[MAX_NAME_LEN - 1] = '\0'; // Ensure null-terminated string
    strncpy(new_person.email, email, MAX_EMAIL_LEN);
    new_person.email[MAX_EMAIL_LEN - 1] = '\0'; // Ensure null-terminated string
    
    list->people[list->num_people++] = new_person;
    
    printf("%s <%s> has been added to the mailing list!\n", name, email);
}

void remove_person(struct mailing_list* list, int index) {
    if (index < 0 || index >= list->num_people) {
        printf("Invalid index!\n");
        return;
    }
    
    printf("%s <%s> has been removed from the mailing list.\n", 
           list->people[index].name, list->people[index].email);
    
    // Shift the remaining elements after the index position by 1 to the left
    for (int i = index; i < list->num_people - 1; ++i) {
        list->people[i] = list->people[i + 1];
    }
    --list->num_people;
}

void display_list(struct mailing_list list) {
    printf("Mailing List:\n");
    for (int i = 0; i < list.num_people; ++i) {
        printf("%d.) %s <%s>\n", i + 1, list.people[i].name, list.people[i].email);
    }
}

int main() {
    struct mailing_list list = { .num_people = 0 };
    int choice, index;
    char name[MAX_NAME_LEN], email[MAX_EMAIL_LEN];
    
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Add person to mailing list.\n");
        printf("2. Remove person from mailing list.\n");
        printf("3. Display mailing list.\n");
        printf("4. Quit.\n");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter person's name: ");
                scanf("%s", name);
                printf("Enter person's email: ");
                scanf("%s", email);
                add_person(&list, name, email);
                break;
                
            case 2:
                printf("Enter index of person to remove: ");
                scanf("%d", &index);
                remove_person(&list, index - 1);
                break;
                
            case 3:
                display_list(list);
                break;
                
            case 4:
                printf("Goodbye!\n");
                exit(0);
                
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}