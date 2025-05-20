//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FLOWERS 10
#define GARDEN_SIZE 5

typedef struct {
    char name[30];
    int blooming; // bloom status: 0 = not blooming, 1 = blooming
} Flower;

void display_garden(Flower flowers[], int flower_count) {
    printf("\n\nYour Tranquil Garden:\n\n");
    for (int i = 0; i < GARDEN_SIZE; i++) {
        for (int j = 0; j < GARDEN_SIZE; j++) {
            if (i < flower_count && j < 1) {
                printf(" %s ", flowers[i].blooming ? flowers[i].name : "[ ]");
            } else {
                printf(" . "); // represent the earth
            }
        }
        printf("\n");
    }
    printf("\n");
}

void plant_flower(Flower flowers[], int *flower_count) {
    if (*flower_count >= MAX_FLOWERS) {
        printf("You have reached the maximum number of flowers in your garden.\n");
        return;
    }
    
    Flower new_flower;
    printf("Enter the name of the flower you wish to plant (Max 30 characters): ");
    scanf("%30s", new_flower.name);
    new_flower.blooming = rand() % 2; // random bloom status
    flowers[*flower_count] = new_flower;
    (*flower_count)++;
    printf("%s has been planted in your garden!\n", new_flower.name);
}

void water_flowers(Flower flowers[], int flower_count) {
    printf("Watering your flowers...\n");
    for (int i = 0; i < flower_count; i++) {
        flowers[i].blooming = 1; // all flowers bloom after watering
        printf("%s is blooming beautifully now!\n", flowers[i].name);
    }
}

void display_flower_info(Flower flowers[], int flower_count) {
    printf("\nFlower Information:\n");
    for (int i = 0; i < flower_count; i++) {
        printf("%d. %s - %s\n", i + 1, flowers[i].name, flowers[i].blooming ? "Blooming" : "Not Blooming");
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    Flower flowers[MAX_FLOWERS];
    int flower_count = 0;
    int choice;

    while (1) {
        printf("Welcome to your peaceful garden!\n");
        printf("1. Plant a flower\n");
        printf("2. Water the flowers\n");
        printf("3. Display garden\n");
        printf("4. Display flower info\n");
        printf("5. Exit\n");
        
        printf("Please choose an option (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                plant_flower(flowers, &flower_count);
                break;
            case 2:
                water_flowers(flowers, flower_count);
                break;
            case 3:
                display_garden(flowers, flower_count);
                break;
            case 4:
                display_flower_info(flowers, flower_count);
                break;
            case 5:
                printf("Thank you for visiting your tranquil garden. Have a peaceful day!\n");
                exit(0);
                break;
            default:
                printf("Invalid option, please choose again.\n");
        }
    }

    return 0;
}