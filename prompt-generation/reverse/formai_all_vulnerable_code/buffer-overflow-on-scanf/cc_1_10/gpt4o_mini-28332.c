//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Creature {
    char *name;
    int age;
} Creature;

Creature* create_creature(const char *name, int age) {
    Creature *new_creature = (Creature*)malloc(sizeof(Creature));
    new_creature->name = (char*)malloc(strlen(name) + 1);
    strcpy(new_creature->name, name);
    new_creature->age = age;
    return new_creature;
}

void destroy_creature(Creature *creature) {
    free(creature->name);
    free(creature);
}

void print_creature(Creature *creature) {
    printf("Creature: %s, Age: %d\n", creature->name, creature->age);
}

void allocate_creatures(Creature ***creatures_array, int *count) {
    printf("How many creatures do you want to summon? ");
    scanf("%d", count);
    *creatures_array = (Creature**)malloc(*count * sizeof(Creature*));
    for(int i = 0; i < *count; i++) {
        char name[50];
        int age;
        printf("Enter name for creature %d: ", i + 1);
        scanf("%s", name);
        printf("Enter age for creature %d: ", i + 1);
        scanf("%d", &age);
        (*creatures_array)[i] = create_creature(name, age);
    }
}

void deallocate_creatures(Creature **creatures_array, int count) {
    for(int i = 0; i < count; i++) {
        destroy_creature(creatures_array[i]);
    }
    free(creatures_array);
}

void show_creature_array(Creature **creatures_array, int count) {
    printf("List of summoned creatures:\n");
    for(int i = 0; i < count; i++) {
        print_creature(creatures_array[i]);
    }
}

int main() {
    Creature **creatures = NULL;
    int count = 0;
    
    allocate_creatures(&creatures, &count);
    
    show_creature_array(creatures, count);
    
    char command;
    do {
        printf("Would you like to summon another creature? (y/n): ");
        scanf(" %c", &command);
        if (command == 'y') {
            Creature **temp = creatures;
            creatures = (Creature**)malloc((count + 1) * sizeof(Creature*));
            for(int i = 0; i < count; i++) {
                creatures[i] = temp[i];
            }
            char name[50];
            int age;
            printf("Enter name for new creature: ");
            scanf("%s", name);
            printf("Enter age for new creature: ");
            scanf("%d", &age);
            creatures[count] = create_creature(name, age);
            count++;
            free(temp);
        }
    } while (command == 'y');
    
    show_creature_array(creatures, count);
    
    deallocate_creatures(creatures, count);
    
    return 0;
}