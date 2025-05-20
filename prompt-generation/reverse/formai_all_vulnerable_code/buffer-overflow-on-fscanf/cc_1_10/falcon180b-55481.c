//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBJECTS 100
#define MAX_RECIPIENTS 1000
#define MAX_MESSAGE_LENGTH 10000

typedef struct {
    char subject[MAX_SUBJECTS];
    char recipients[MAX_RECIPIENTS][MAX_SUBJECTS];
    char message[MAX_MESSAGE_LENGTH];
} message_t;

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    message_t message;
    int num_recipients = 0;
    char *recipient;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", argv[1]);
        return 1;
    }

    output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", argv[2]);
        fclose(input_file);
        return 1;
    }

    while (fscanf(input_file, "Subject: %s\nTo: %s\n\n%[^\n]", message.subject, message.recipients[num_recipients], message.message) == 3) {
        num_recipients++;
        if (num_recipients >= MAX_RECIPIENTS) {
            fprintf(stderr, "Error: Too many recipients (max %d)\n", MAX_RECIPIENTS);
            fclose(input_file);
            fclose(output_file);
            return 1;
        }
    }

    fclose(input_file);

    fprintf(output_file, "Subject: %s\n", message.subject);
    for (int i = 0; i < num_recipients; i++) {
        fprintf(output_file, "To: %s\n", message.recipients[i]);
    }
    fprintf(output_file, "\n%s", message.message);

    fclose(output_file);

    return 0;
}