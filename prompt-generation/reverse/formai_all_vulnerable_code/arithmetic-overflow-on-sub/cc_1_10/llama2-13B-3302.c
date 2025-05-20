//LLAMA2-13B DATASET v1.0 Category: Audio processing ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LEN 1024
#define SPELL_COUNT 10

struct spell {
    char name[20];
    char incantation[50];
    int power;
};

struct knight {
    char name[20];
    int health;
    int attack;
    int defense;
};

int main() {
    struct spell spells[SPELL_COUNT] = {
        {"healing", "Regenerate 10 health over 5 seconds"},
        {"fireball", "Deal 20 damage to all enemies"},
        {"shield", "Increase defense by 10 for 10 seconds"},
        {"poison", "Deal 10 damage over 5 seconds"},
        {"ice", "Freeze all enemies for 5 seconds"},
    };

    struct knight knights[5] = {
        {"Sir Reginald", 100, 20, 15},
        {"Lady Elizabeth", 80, 15, 20},
        {"Sir Edward", 60, 25, 10},
        {"Sir John", 40, 30, 5},
        {"Sir Thomas", 20, 40, 25},
    };

    int current_spell = 0;
    int current_knight = 0;

    while (1) {
        printf("Current spell: %s\n", spells[current_spell].name);
        printf("Current knight: %s\n", knights[current_knight].name);

        if (getchar() == '1') {
            current_spell++;
            if (current_spell >= SPELL_COUNT) {
                current_spell = 0;
            }
        } else if (getchar() == '2') {
            current_knight++;
            if (current_knight >= 5) {
                current_knight = 0;
            }
        } else if (getchar() == '3') {
            int target = getchar() - '1';
            if (target < 1 || target > 5) {
                continue;
            }
            knights[target - 1].health += spells[current_spell].power;
            printf("Healed %s to %d health\n", knights[target - 1].name, knights[target - 1].health);
        } else {
            continue;
        }
    }

    return 0;
}