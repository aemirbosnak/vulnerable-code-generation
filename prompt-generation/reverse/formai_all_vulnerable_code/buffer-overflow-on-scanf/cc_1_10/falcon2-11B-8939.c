//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    char c;
    printf("Enter the number of rooms in the haunted house: ");
    scanf("%d", &n);

    printf("\nCreating haunted house with %d rooms...\n", n);

    for(i = 1; i <= n; i++) {
        printf("Creating Room %d...\n", i);
    }

    printf("Haunted house created successfully!\n");

    printf("\nLet's explore the haunted house:\n");

    printf("Room 1:\n");
    printf("A dark and spooky room with cobwebs and an old rocking chair.\n");

    printf("Room 2:\n");
    printf("A creepy room with flickering candles and a portrait of a ghost.\n");

    printf("Room 3:\n");
    printf("A room with a broken mirror and an old gramophone playing eerie music.\n");

    printf("Room 4:\n");
    printf("A room with a skeleton hanging from the ceiling and a dusty bookcase.\n");

    printf("Room 5:\n");
    printf("A room with a flickering torchlight and a ghostly figure on the wall.\n");

    printf("Room 6:\n");
    printf("A room with a creaking door and an old grandfather clock ticking loudly.\n");

    printf("Room 7:\n");
    printf("A room with a broken chandelier and a painting of a witch.\n");

    printf("Room 8:\n");
    printf("A room with a dusty bookcase and a whispering wind.\n");

    printf("\nEscape from the haunted house!\n");

    printf("You escape from the haunted house and run back to your home.\n");

    printf("Good job! You escaped from the haunted house!\n");

    printf("\nPress any key to exit...\n");
    getchar();

    return 0;
}