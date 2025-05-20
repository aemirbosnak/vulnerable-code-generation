//FormAI DATASET v1.0 Category: Phone Book ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define Contact data structure */
struct Contact {
    char name[50];
    char phone[15];
};

/* Function declarations */
void add_contact(struct Contact **, int *);
void delete_contact(struct Contact **, int *);
void search_contact(struct Contact *, int);
void print_phonebook(struct Contact *, int);
void save_phonebook(struct Contact *, int);
void load_phonebook(struct Contact **, int *);

/* Main function */
int main() {
    struct Contact *phonebook = NULL; // Initialize phonebook to NULL
    int num_contacts = 0; // Initialize number of contacts to 0
    
    /* Program startup message */
    printf("Welcome to your Cyberphonebook!\n");
    printf("Enter 'add' to add a contact, 'delete' to delete a contact, 'search' to search for a contact, 'print' to print your phonebook, 'save' to save your phonebook, or 'load' to load a phonebook.\n");
    
    /* Loop to continuously prompt user for actions */
    char input[10];
    while (1) {
        printf("> ");
        scanf("%s", input);
        
        /* Conditional statements for different actions */
        if (strcmp(input, "add") == 0) {
            add_contact(&phonebook, &num_contacts);
        } else if (strcmp(input, "delete") == 0) {
            delete_contact(&phonebook, &num_contacts);
        } else if (strcmp(input, "search") == 0) {
            search_contact(phonebook, num_contacts);
        } else if (strcmp(input, "print") == 0) {
            print_phonebook(phonebook, num_contacts);
        } else if (strcmp(input, "save") == 0) {
            save_phonebook(phonebook, num_contacts);
        } else if (strcmp(input, "load") == 0) {
            load_phonebook(&phonebook, &num_contacts);
        } else {
            printf("Invalid command. Try again.\n");
        }
    }
    
    return 0;
}

/* Function to add a new contact */
void add_contact(struct Contact **phonebook, int *num_contacts) {
    struct Contact new_contact; // Create new Contact struct
    printf("Enter name: ");
    scanf("%s", new_contact.name);
    printf("Enter phone number: ");
    scanf("%s", new_contact.phone);
    
    /* Resize phonebook to accomodate new contact */
    *phonebook = (struct Contact *)realloc(*phonebook, (*num_contacts + 1) * sizeof(struct Contact));
    (*phonebook)[*num_contacts] = new_contact;
    *num_contacts += 1;
    
    printf("New contact added.\n");
}

/* Function to delete a contact */
void delete_contact(struct Contact **phonebook, int *num_contacts) {
    char name[50];
    printf("Enter name of contact to delete: ");
    scanf("%s", name);
    
    /* Loop through phonebook to find contact */
    int i;
    for (i = 0; i < *num_contacts; i++) {
        if (strcmp((*phonebook)[i].name, name) == 0) {
            /* Shift remaining contacts left to fill gap */
            int j;
            for (j = i; j < (*num_contacts - 1); j++) {
                (*phonebook)[j] = (*phonebook)[j+1];
            }
            
            /* Resize phonebook to accomodate removed contact */
            *phonebook = (struct Contact *)realloc(*phonebook, (*num_contacts - 1) * sizeof(struct Contact));
            *num_contacts -= 1;
            
            printf("%s has been deleted from your phonebook.\n", name);
            return;
        }
    }
    
    /* Contact not found */
    printf("%s not found in your phonebook.\n", name);
}

/* Function to search for a contact */
void search_contact(struct Contact *phonebook, int num_contacts) {
    char name[50];
    printf("Enter name of contact to search for: ");
    scanf("%s", name);
    
    /* Loop through phonebook to find contact */
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("%s's phone number is %s.\n", name, phonebook[i].phone);
            return;
        }
    }
    
    /* Contact not found */
    printf("%s not found in your phonebook.\n", name);
}

/* Function to print phonebook */
void print_phonebook(struct Contact *phonebook, int num_contacts) {
    if (num_contacts == 0) {
        printf("Your phonebook is empty.\n");
    } else {
        printf("Your phonebook:\n");
        int i;
        for (i = 0; i < num_contacts; i++) {
            printf("%s: %s\n", phonebook[i].name, phonebook[i].phone);
        }
    }
}

/* Function to save phonebook to file */
void save_phonebook(struct Contact *phonebook, int num_contacts) {
    char filename[50];
    printf("Enter filename to save phonebook to: ");
    scanf("%s", filename);
    
    FILE *file = fopen(filename, "w");
    
    int i;
    for (i = 0; i < num_contacts; i++) {
        fprintf(file, "%s,%s\n", phonebook[i].name, phonebook[i].phone);
    }
    
    fclose(file);
    printf("Phonebook saved to %s.\n", filename);
}

/* Function to load phonebook from file */
void load_phonebook(struct Contact **phonebook, int *num_contacts) {
    char filename[50];
    printf("Enter filename to load phonebook from: ");
    scanf("%s", filename);
    
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: file not found.\n");
        return;
    }
    
    int i;
    char temp[50];
    while (fgets(temp, sizeof(temp), file)) {
        *phonebook = (struct Contact *)realloc(*phonebook, (*num_contacts + 1) * sizeof(struct Contact));
        sscanf(temp, "%[^,],%s", (*phonebook)[*num_contacts].name, (*phonebook)[*num_contacts].phone);
        *num_contacts += 1;
    }
    
    fclose(file);
    printf("%d contacts loaded from %s.\n", *num_contacts, filename);
}