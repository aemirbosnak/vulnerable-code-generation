//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ATTACKS 100
#define MAX_ATTACK_LENGTH 20

struct attack {
    char pattern[MAX_ATTACK_LENGTH];
    int length;
    int count;
};

int compare(const void *a, const void *b) {
    struct attack *attack1 = (struct attack *) a;
    struct attack *attack2 = (struct attack *) b;

    if (attack1->count > attack2->count) {
        return -1;
    } else if (attack1->count < attack2->count) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char input[1000];
    int i = 0, j = 0, k = 0, n = 0, count = 0;
    struct attack attacks[MAX_ATTACKS];

    printf("Enter the input string: ");
    scanf("%s", input);

    for (i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            if (attacks[k].length == MAX_ATTACK_LENGTH) {
                k++;
            }

            attacks[k].pattern[j] = input[i];
            j++;
            attacks[k].length++;
        } else {
            if (j > 0) {
                attacks[k].pattern[j] = '\0';
                j = 0;
                k++;
            }
        }
    }

    qsort(attacks, MAX_ATTACKS, sizeof(struct attack), compare);

    printf("\nNumber of attacks: %d\n", k);

    for (n = 0; n < k; n++) {
        printf("Attack %d: %s\n", n+1, attacks[n].pattern);
        printf("Number of occurrences: %d\n", attacks[n].count);
    }

    return 0;
}