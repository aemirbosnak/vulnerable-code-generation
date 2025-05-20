//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

// QR code reader function
void qr_reader(char *filename) {
    FILE *fptr;
    int i, j, k, l, m, n, count, state = 0;
    char ch, text[1000];
    int data_count = 0;
    int data_type = 0;

    // Open input file
    fptr = fopen(filename, "rb");

    // Check if file exists
    if (fptr == NULL) {
        printf("File not found.\n");
        exit(0);
    }

    // Read QR code data
    while ((ch = fgetc(fptr))!= EOF) {
        if (isprint(ch)) {
            text[data_count++] = ch;
        } else if (ch == '\n') {
            text[data_count] = '\0';
            printf("%s\n", text);
            data_count = 0;
        } else if (ch == '\r') {
            text[data_count] = '\0';
            printf("%s\n", text);
            data_count = 0;
        }
    }

    // Close input file
    fclose(fptr);
}

int main() {
    int i, n, choice;
    char filename[100];

    // Get number of files to read
    printf("Enter number of files to read: ");
    scanf("%d", &n);

    // Loop through files
    for (i = 0; i < n; i++) {
        // Get filename
        printf("Enter filename %d: ", i+1);
        scanf("%s", filename);

        // Read QR code data
        qr_reader(filename);
    }

    return 0;
}