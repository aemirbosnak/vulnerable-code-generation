//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100

typedef struct {
    char *text;
    int weight;
} Fortune;

Fortune fortunes[MAX_FORTUNES] = {
    {"Thou shalt find great treasure on thy journey.", 1},
    {"A mighty dragon shall cross thy path.", 2},
    {"Thou shalt meet a fair maiden in the forest.", 3},
    {"Beware the treacherous bridge ahead.", 4},
    {"Thou shalt be granted a boon by the king.", 5},
    {"A wise old sage shall guide thee.", 6},
    {"Thou shalt face a fearsome foe in battle.", 7},
    {"Thou shalt discover a hidden passage.", 8},
    {"A talking animal shall reveal secrets to thee.", 9},
    {"Thou shalt encounter a magical artifact.", 10}
};

int main() {
    srand(time(NULL));
    int choice;
    printf("Welcome to the medieval fortune teller!\n");
    printf("What wouldst thou like to know?\n");
    printf("1. Thy future\n");
    printf("2. Thy love life\n");
    printf("3. Thy wealth\n");
    scanf("%d", &choice);
    if (choice < 1 || choice > 3) {
        printf("Invalid choice! The spirits are angered!\n");
        return 1;
    }
    Fortune *fortune = NULL;
    int total_weight = 0;
    for (int i = 0; i < MAX_FORTUNES; i++) {
        if (fortunes[i].weight == choice) {
            fortune = &fortunes[i];
            break;
        }
        total_weight += fortunes[i].weight;
    }
    if (fortune == NULL) {
        printf("No fortune found for that choice.\n");
        return 1;
    }
    printf("The spirits have spoken:\n%s\n", fortune->text);
    return 0;
}