//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 256
#define MAX_PHONE_NUM_LEN 20

// Structure to store contact information
typedef struct {
    char name[MAX_NAME_LEN];
    char phone_num[MAX_PHONE_NUM_LEN];
} contact_t;

// Function to generate a random name and phone number
void generate_contact(contact_t *contact) {
    int i, j;
    char letters[26];
    char nums[10];

    // Generate a random name
    for (i = 0; i < MAX_NAME_LEN; i++) {
        letters[i] = 'a' + (rand() % 26);
    }
    strcpy(contact->name, letters);

    // Generate a random phone number
    for (j = 0; j < MAX_PHONE_NUM_LEN; j++) {
        nums[j] = '0' + (rand() % 10);
    }
    strcpy(contact->phone_num, nums);
}

// Function to print the contact information
void print_contact(contact_t *contact) {
    printf("Name: %s\nPhone Number: %s\n", contact->name, contact->phone_num);
}

int main() {
    // Create an array of contact structures
    contact_t contacts[5];

    // Initialize the contacts
    for (int i = 0; i < 5; i++) {
        generate_contact(&contacts[i]);
    }

    // Print the contacts
    for (int i = 0; i < 5; i++) {
        print_contact(&contacts[i]);
    }

    return 0;
}