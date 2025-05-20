//FormAI DATASET v1.0 Category: QR code reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define QR_CODE_SIZE 21

/*
 * The QR code struct represents a QR code by a 21 character string.
 */
typedef struct qr_code {
    char code[QR_CODE_SIZE + 1];
} qr_code_t;

/*
 * Reads a QR code from user input and returns a dynamically allocated
 * QR code struct containing the code.
 */
qr_code_t *read_qr_code() {
    char input[QR_CODE_SIZE + 1];

    printf("Please enter a 21 character QR code: ");
    scanf("%s", input);

    // Make sure input is exactly 21 characters
    if (strlen(input) != QR_CODE_SIZE) {
        printf("Invalid QR code.\n");
        return NULL;
    }

    qr_code_t *qr = malloc(sizeof(qr_code_t));
    strncpy(qr->code, input, QR_CODE_SIZE);

    return qr;
}

/*
 * Looks up a QR code in the database and returns the corresponding entry.
 * In this example, we simply return a hardcoded value for "ABCDEF123456".
 */
char *lookup_qr_code(qr_code_t *qr) {
    if (strcmp(qr->code, "ABCDEF123456") == 0)
        return "A cool item";
    else
        return NULL;
}

int main() {
    qr_code_t *qr = read_qr_code();

    if (qr == NULL)
        return 1;

    char *entry = lookup_qr_code(qr);

    if (entry == NULL) {
        printf("QR code not found.\n");
        return 1;
    }

    printf("Entry for QR code %s: %s\n", qr->code, entry);

    free(qr);

    return 0;
}