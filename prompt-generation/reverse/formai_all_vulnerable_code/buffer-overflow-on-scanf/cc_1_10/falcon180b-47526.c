//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_DAYS 30

struct City {
    char name[20];
    int temperature[MAX_DAYS];
};

void generateRandomCity(struct City* city) {
    for(int i = 0; i < MAX_DAYS; i++) {
        city->temperature[i] = rand() % 100;
    }
}

int main() {
    srand(time(NULL));

    struct City cities[MAX_CITIES];

    for(int i = 0; i < MAX_CITIES; i++) {
        printf("Enter city name: ");
        scanf("%s", cities[i].name);
        generateRandomCity(&cities[i]);
    }

    int day = 0;

    while(day < MAX_DAYS) {
        printf("\nDay %d\n", day+1);

        for(int i = 0; i < MAX_CITIES; i++) {
            printf("%s: ", cities[i].name);

            for(int j = 0; j < MAX_DAYS; j++) {
                if(j < day) {
                    printf("%d ", cities[i].temperature[j]);
                } else {
                    printf("- ");
                }
            }

            printf("\n");
        }

        day++;

        if(day == MAX_DAYS) {
            break;
        }

        printf("\nPress enter to continue...\n");
        getchar();
    }

    return 0;
}