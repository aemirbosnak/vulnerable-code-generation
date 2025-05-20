//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define BITS_PER_BYTE 8
#define BITS_PER_LONG 32

typedef struct {
    uint32_t id;
    char name[32];
} suspect;

void print_binary(uint32_t num) {
    for (int i = BITS_PER_LONG - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

void process_evidence(const char* evidence) {
    suspect suspects[6] = {
        {0x12345678, "Moriarty"},
        {0x23456789, "James Moriarty"},
        {0x34567890, "Professor Moriarty"},
        {0x45678901, "Colonel Moriarty"},
        {0x56789012, "Doctor Moriarty"},
        {0x67890123, "Mrs. Hudson"}
    };

    uint32_t hash = 0;
    int len = strlen(evidence);

    for (int i = 0; i < len; i++) {
        hash ^= evidence[i];
    }

    for (int i = 0; i < 6; i++) {
        if (hash == suspects[i].id) {
            printf("Suspect %s has been identified!\n", suspects[i].name);
            return;
        }
    }

    printf("No suspect has been identified.\n");
}

int main() {
    char evidence[128];

    printf("Enter the evidence (a string): ");
    scanf("%s", evidence);

    process_evidence(evidence);

    return 0;
}