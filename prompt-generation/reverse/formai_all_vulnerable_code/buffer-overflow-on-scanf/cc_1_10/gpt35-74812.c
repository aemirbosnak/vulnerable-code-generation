//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100

// Function to detect intrusion based on suspicious lines
void detect_intrusion(char suspicious_strings[][100], int no_of_suspicious_lines, char *filename) {
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: File open failed!");
        return;
    }

    char buffer[150];
    int line_number = 1;
    int count = 0;
    int suspicious_count = 0;

    // Read file line by line
    while (fgets(buffer, 150, fp) != NULL) {

        // Check for suspicious strings
        for (int i = 0; i < no_of_suspicious_lines; i++) {
            if (strstr(buffer, suspicious_strings[i]) != NULL) {
                printf("Suspicious string '%s' found in line %d:\n", suspicious_strings[i], line_number);
                printf("%s", buffer);
                suspicious_count++;
            }
        }

        // Stop checking if too many suspicious strings detected
        if (suspicious_count > 5) {
            printf("Intrusion detected. Too many suspicious strings found.");
            break;
        }

        count++;
        line_number++;

        if (count >= MAX_LINES) {
            printf("Intrusion not detected. End of file reached.");
            break;
        }
    }

    fclose(fp);
}

int main() {
    char suspicious_strings[][100] = {"rm -rf", "sudo rm -rf", "ssh ", "curl ", "wget "};
    int no_of_suspicious_lines = sizeof(suspicious_strings) / sizeof(suspicious_strings[0]);

    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    detect_intrusion(suspicious_strings, no_of_suspicious_lines, filename);

    return 0;
}