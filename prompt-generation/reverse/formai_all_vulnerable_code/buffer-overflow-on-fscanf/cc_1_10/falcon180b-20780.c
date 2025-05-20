//Falcon-180B DATASET v1.0 Category: Email Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 1000

// Struct to hold email information
typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    int length;
} Email;

// Function to compare two emails by length
int compare_emails(const void *a, const void *b) {
    Email *email_a = (Email *)a;
    Email *email_b = (Email *)b;

    if (email_a->length > email_b->length) {
        return -1;
    } else if (email_a->length < email_b->length) {
        return 1;
    } else {
        return 0;
    }
}

// Main function to read emails from a file and sort them by length
int main() {
    FILE *file;
    Email emails[MAX_EMAILS];
    int num_emails = 0;

    // Open the email file for reading
    file = fopen("emails.txt", "r");
    if (file == NULL) {
        printf("Error opening email file.\n");
        return 1;
    }

    // Read emails from the file
    while (fscanf(file, "%s %s %d\n", emails[num_emails].subject, emails[num_emails].body, &emails[num_emails].length)!= EOF) {
        num_emails++;
    }

    // Close the email file
    fclose(file);

    // Sort the emails by length
    qsort(emails, num_emails, sizeof(Email), compare_emails);

    // Print the sorted emails
    printf("Sorted emails by length:\n");
    for (int i = 0; i < num_emails; i++) {
        printf("%s (%d characters)\n", emails[i].subject, emails[i].length);
    }

    return 0;
}