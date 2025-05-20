//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

// Struct to hold mailing list data
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} mailing_list_entry;

// Function to compare two strings (case insensitive)
int strcasecmp(const char* str1, const char* str2) {
    while (*str1 && *str2 && (*str1 == *str2 || (*str1 >= 'a' && *str1 <= 'z' && *str2 >= 'A' && *str2 <= 'Z') || (*str1 >= 'A' && *str1 <= 'Z' && *str2 >= 'a' && *str2 <= 'z'))) {
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}

// Function to sort mailing list entries by name
int compare_entries(const void* a, const void* b) {
    const mailing_list_entry* entry1 = (const mailing_list_entry*)a;
    const mailing_list_entry* entry2 = (const mailing_list_entry*)b;
    return strcasecmp(entry1->name, entry2->name);
}

// Function to read mailing list from file
void read_mailing_list(mailing_list_entry* list, int max_entries, FILE* file) {
    int num_entries = 0;
    while (fscanf(file, "%s %s %s %s", list[num_entries].name, list[num_entries].email, list[num_entries].name, list[num_entries].email) == 4 && num_entries < max_entries) {
        num_entries++;
    }
}

// Function to write mailing list to file
void write_mailing_list(mailing_list_entry* list, int num_entries, FILE* file) {
    for (int i = 0; i < num_entries; i++) {
        fprintf(file, "%s %s %s %s\n", list[i].name, list[i].email, list[i].name, list[i].email);
    }
}

// Function to send email to mailing list
void send_email(mailing_list_entry* list, int num_entries, const char* subject, const char* message) {
    for (int i = 0; i < num_entries; i++) {
        printf("Sending email to %s (%s)\n", list[i].name, list[i].email);
        // TODO: Implement email sending code
    }
}

// Main function
int main() {
    mailing_list_entry list[100];
    int num_entries = 0;

    // Read mailing list from file
    FILE* file = fopen("mailing_list.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open mailing_list.txt\n");
        return 1;
    }
    read_mailing_list(list, 100, file);
    fclose(file);

    // Sort mailing list by name
    qsort(list, num_entries, sizeof(mailing_list_entry), compare_entries);

    // Send email to mailing list
    send_email(list, num_entries, "Test Email", "This is a test email sent using the mailing list manager.");

    return 0;
}