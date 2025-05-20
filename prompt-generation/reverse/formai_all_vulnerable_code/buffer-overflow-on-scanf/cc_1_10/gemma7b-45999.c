//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Knight {
    char name[20];
    int strength, courage, wisdom;
    struct Knight *next;
} Knight;

Knight *insertKnight(Knight *head) {
    Knight *newKnight = (Knight *)malloc(sizeof(Knight));
    printf("Enter the name of the knight: ");
    scanf("%s", newKnight->name);
    printf("Enter the strength of the knight: ");
    scanf("%d", &newKnight->strength);
    printf("Enter the courage of the knight: ");
    scanf("%d", &newKnight->courage);
    printf("Enter the wisdom of the knight: ");
    scanf("%d", &newKnight->wisdom);

    newKnight->next = head;
    head = newKnight;

    return head;
}

int searchKnight(Knight *head, char *name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            return 1;
        }
        head = head->next;
    }

    return 0;
}

int main() {
    Knight *head = NULL;
    head = insertKnight(head);
    head = insertKnight(head);
    head = insertKnight(head);

    char *name = "Sir Robin";
    int result = searchKnight(head, name);

    if (result) {
        printf("Knight found!\n");
    } else {
        printf("Knight not found.\n");
    }

    return 0;
}