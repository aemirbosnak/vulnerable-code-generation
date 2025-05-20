//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define CHECKSUM_LENGTH 8
#define CHECKSUM_VALUE 42

int is_valid_line(char* line) {
    int length = strlen(line);
    return length <= MAX_LINE_LENGTH && length > 0;
}

int calculate_checksum(char* line) {
    int sum = 0;
    int length = strlen(line);

    for (int i = 0; i < length; i++) {
        sum += line[i];
    }

    return sum % CHECKSUM_VALUE;
}

int main() {
    FILE* file;
    char line[MAX_LINE_LENGTH];

    printf("Enter filename: ");
    scanf("%s", line);

    file = fopen(line, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (is_valid_line(line)) {
            int checksum = calculate_checksum(line);

            printf("Line: %s\n", line);
            printf("Checksum: %d\n", checksum);
        }
    }

    fclose(file);

    return 0;
}