//Code Llama-13B DATASET v1.0 Category: Intrusion detection system ; Style: configurable
/* Intrusion Detection System (IDS) Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIGNATURES 100
#define MAX_SIGNATURE_LEN 100
#define MAX_PAYLOAD_LEN 1000

typedef struct {
    char signature[MAX_SIGNATURE_LEN];
    int (*handler)(char*);
} Signature;

int check_signature(char* payload, Signature* signatures, int num_signatures) {
    int i;
    for (i = 0; i < num_signatures; i++) {
        if (strstr(payload, signatures[i].signature) != NULL) {
            return signatures[i].handler(payload);
        }
    }
    return 0;
}

int handle_signature_1(char* payload) {
    printf("Signature 1 detected!\n");
    return 1;
}

int handle_signature_2(char* payload) {
    printf("Signature 2 detected!\n");
    return 2;
}

int main() {
    Signature signatures[MAX_SIGNATURES] = {
        {"Sig1", handle_signature_1},
        {"Sig2", handle_signature_2}
    };

    char payload[MAX_PAYLOAD_LEN];
    int num_signatures = 2;

    while (1) {
        printf("Enter payload: ");
        scanf("%s", payload);
        int result = check_signature(payload, signatures, num_signatures);
        if (result == 1) {
            printf("Signature 1 detected!\n");
        } else if (result == 2) {
            printf("Signature 2 detected!\n");
        } else {
            printf("No signatures detected.\n");
        }
    }

    return 0;
}