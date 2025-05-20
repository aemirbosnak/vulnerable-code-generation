//MISTRAL-7B DATASET v1.0 Category: System administration ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_POEMS 100
#define POEM_SIZE 256

typedef struct {
    char poem[POEM_SIZE];
    int index;
} Poem;

Poem poems[MAX_POEMS];
int head = 0, tail = 0;

void add_poem() {
    if ((tail + 1) % MAX_POEMS == head) {
        printf("Buffer is full. Cannot add poem.\n");
        return;
    }

    printf("Enter a poem:\n");
    scanf("%s", poems[tail].poem);
    poems[tail].index = tail;
    tail = (tail + 1) % MAX_POEMS;
}

void remove_poem() {
    if (head == tail) {
        printf("Buffer is empty. Cannot remove poem.\n");
        return;
    }

    int index = head;
    head = (head + 1) % MAX_POEMS;

    printf("Removed poem with index %d: %s\n", index, poems[index].poem);
}

void display_poems() {
    if (head == tail) {
        printf("Buffer is empty.\n");
        return;
    }

    int i;
    for (i = head; i != tail; i = (i + 1) % MAX_POEMS) {
        printf("Poem %d: %s\n", i, poems[i].poem);
    }

    if (i == tail) {
        printf("Last poem: %s\n", poems[i].poem);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add poem\n");
        printf("2. Remove poem\n");
        printf("3. Display poems\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_poem();
                break;
            case 2:
                remove_poem();
                break;
            case 3:
                display_poems();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}