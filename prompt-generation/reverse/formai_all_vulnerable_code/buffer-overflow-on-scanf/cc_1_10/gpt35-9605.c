//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: active
#include<stdio.h>
#include<stdlib.h>

// Define a struct for our spaceship
struct spaceship{
    int x;
    int y;
    int health;
    int fuel;
};

// Function to move spaceship
void move_spaceship(struct spaceship *s, int x, int y){
    s->x += x;
    s->y += y;
    printf("Spaceship moved to (%d, %d)\n", s->x, s->y);
}

// Function to attack enemy spaceship
void attack_enemy(struct spaceship *s, struct spaceship *enemy){
    enemy->health -= 10; // Reduce enemy health
    printf("Enemy spaceship health: %d\n", enemy->health);
    if(enemy->health <= 0){
        printf("Enemy spaceship destroyed!\n");
    }
}

int main(){
    // Create instances of spaceship
    struct spaceship my_spaceship = {0, 0, 100, 50};
    struct spaceship enemy_spaceship = {10, 10, 50, 30};

    printf("Welcome to the Space Adventure game!\n");

    // Game loop
    while(1){
        int choice;
        printf("\nWhat would you like to do?\n");
        printf("1. Move spaceship\n");
        printf("2. Attack enemy spaceship\n");
        printf("3. Quit game\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter x and y co-ordinates to move spaceship: ");
                int x, y;
                scanf("%d %d", &x, &y);
                move_spaceship(&my_spaceship, x, y);
                my_spaceship.fuel -= 5; // Reduce fuel
                printf("Spaceship fuel remaining: %d\n", my_spaceship.fuel);
                break;
            case 2:
                attack_enemy(&my_spaceship, &enemy_spaceship);
                break;
            case 3:
                printf("Quitting game...\n");
                exit(0); // Exit program
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

        // Check if player has run out of fuel or health
        if(my_spaceship.fuel <= 0){
            printf("Out of fuel! Game over\n");
            exit(0);
        }
        if(my_spaceship.health <= 0){
            printf("Spaceship destroyed! Game over\n");
            exit(0);
        }
    }

    return 0;
}