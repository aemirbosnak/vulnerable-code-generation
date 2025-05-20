//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000
#define MAX_NUM_STRINGS 100

// Function prototypes
void read_strings(char *strings[]);
void sort_strings(char *strings[]);
void print_sorted_strings(char *strings[]);

int main() {
    char *strings[MAX_NUM_STRINGS];
    int num_strings;

    // Read in strings and store in array
    printf("Enter the number of strings: ");
    scanf("%d", &num_strings);

    if (num_strings > MAX_NUM_STRINGS) {
        printf("Error: Too many strings.\n");
        return 1;
    }

    read_strings(strings);

    // Sort strings in alphabetical order
    sort_strings(strings);

    // Print sorted strings
    printf("Sorted strings:\n");
    print_sorted_strings(strings);

    return 0;
}

// Read strings from user input and store in array
void read_strings(char *strings[]) {
    int i;

    for (i = 0; i < MAX_NUM_STRINGS; i++) {
        printf("Enter string %d: ", i + 1);
        scanf("%s", strings[i]);

        if (strlen(strings[i]) > MAX_STRING_LENGTH) {
            printf("Error: String too long.\n");
            exit(1);
        }
    }
}

// Sort strings in alphabetical order
void sort_strings(char *strings[]) {
    int i, j;
    char temp[MAX_STRING_LENGTH];

    for (i = 0; i < MAX_NUM_STRINGS - 1; i++) {
        for (j = i + 1; j < MAX_NUM_STRINGS; j++) {
            if (strcmp(strings[i], strings[j]) > 0) {
                strcpy(temp, strings[i]);
                strcpy(strings[i], strings[j]);
                strcpy(strings[j], temp);
            }
        }
    }
}

// Print sorted strings
void print_sorted_strings(char *strings[]) {
    int i;

    for (i = 0; i < MAX_NUM_STRINGS; i++) {
        printf("%s\n", strings[i]);
    }
}