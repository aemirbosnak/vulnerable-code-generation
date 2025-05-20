//Falcon2-11B DATASET v1.0 Category: Password management ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define constants
#define MAX_PASSWORD_LENGTH 100
#define MAX_PASSWORD_COUNT 100

// Define data structures
typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int count;
} Password;

Password password[MAX_PASSWORD_COUNT];

int main(int argc, char *argv[]) {
    // Check command-line arguments
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    // Read passwords from file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 2;
    }

    char line[MAX_PASSWORD_LENGTH];
    int password_count = 0;

    while (fgets(line, sizeof(line), file)) {
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        Password *p = &password[password_count];
        strncpy(p->password, line, MAX_PASSWORD_LENGTH);
        p->count = 1;
        password_count++;
    }

    fclose(file);

    // Print passwords
    printf("Passwords:n");
    for (int i = 0; i < password_count; i++) {
        Password *p = &password[i];
        printf("%d. %s (%d times)\n", i + 1, p->password, p->count);
    }

    return 0;
}