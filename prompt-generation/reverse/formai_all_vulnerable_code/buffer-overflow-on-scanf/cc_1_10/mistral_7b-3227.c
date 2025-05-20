//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUM_VOTERS 100
#define TABLE_SIZE 13

typedef struct {
    char name[50];
    int president;
    int vice_president;
} Voter;

typedef struct HashNode {
    Voter voter;
    struct HashNode *next;
} HashNode;

typedef struct HashTable {
    HashNode *table[TABLE_SIZE];
} HashTable;

unsigned int hash(char *str) {
    unsigned int hash = 0;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % TABLE_SIZE;
}

void add_voter(HashTable *ht, Voter voter) {
    unsigned int index = hash(voter.name);
    HashNode *new_node = (HashNode *) malloc(sizeof(HashNode));

    strcpy(new_node->voter.name, voter.name);
    new_node->voter.president = voter.president;
    new_node->voter.vice_president = voter.vice_president;
    new_node->next = ht->table[index];
    ht->table[index] = new_node;
}

void print_results(HashTable ht) {
    int i, president, vice_president;

    for (i = 0; i < TABLE_SIZE; i++) {
        if (ht.table[i]) {
            president = ht.table[i]->voter.president;
            vice_president = ht.table[i]->voter.vice_president;

            printf("Voter %s voted for President %d and Vice President %d\n", ht.table[i]->voter.name, president, vice_president);

            president += ht.table[i]->voter.president;
            vice_president += ht.table[i]->voter.vice_president;
        }
    }

    printf("\nPresident: %d\n", president);
    printf("Vice President: %d\n", vice_president);
}

int main() {
    HashTable ht;
    int i;
    Voter voter;

    memset(ht.table, 0, sizeof(ht.table));

    for (i = 0; i < NUM_VOTERS; i++) {
        printf("Enter voter %d name: ", i + 1);
        scanf("%s", voter.name);

        printf("Enter voter %d President vote: ", i + 1);
        scanf("%d", &voter.president);

        printf("Enter voter %d Vice President vote: ", i + 1);
        scanf("%d", &voter.vice_president);

        add_voter(&ht, voter);
    }

    print_results(ht);

    return 0;
}