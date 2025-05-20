//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1000

// Function prototypes
void calculate_checksum(char* line, char* checksum);
bool is_valid_checksum(char* line, char* checksum);

int main() {
    char line[MAX_LINE_LENGTH];
    char checksum[MAX_LINE_LENGTH];
    bool valid_checksum = false;

    printf("Enter a line of text: ");
    fgets(line, MAX_LINE_LENGTH, stdin);

    // Remove newline character
    line[strcspn(line, "\n")] = '\0';

    // Calculate checksum
    calculate_checksum(line, checksum);

    // Check if checksum is valid
    valid_checksum = is_valid_checksum(line, checksum);

    if (valid_checksum) {
        printf("Checksum is valid.\n");
    } else {
        printf("Checksum is invalid.\n");
    }

    return 0;
}

void calculate_checksum(char* line, char* checksum) {
    int i, sum = 0;

    for (i = 0; line[i]!= '\0'; i++) {
        sum += (int)line[i];
    }

    sprintf(checksum, "%d", sum);
}

bool is_valid_checksum(char* line, char* checksum) {
    int i, line_sum = 0, checksum_int = 0;

    for (i = 0; line[i]!= '\0'; i++) {
        if (isdigit(line[i])) {
            line_sum += (int)line[i] - '0';
        }
    }

    sscanf(checksum, "%d", &checksum_int);

    return (line_sum == checksum_int);
}