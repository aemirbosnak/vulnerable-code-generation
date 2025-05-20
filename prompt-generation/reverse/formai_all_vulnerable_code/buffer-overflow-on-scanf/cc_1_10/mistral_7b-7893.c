//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TIME_TRAVELERS 10

typedef struct TimeTraveler {
    char name[50];
    int age;
    time_t travel_time;
} TimeTraveler;

void print_travelers(TimeTraveler travelers[]) {
    int i;
    for (i = 0; i < 10; i++) {
        printf("Traveler %d: %s, Age: %d, Travel Time: %s\n", i + 1, travelers[i].name, travelers[i].age, ctime(&travelers[i].travel_time));
    }
}

void travel_in_time(TimeTraveler* traveler, time_t destination) {
    traveler->travel_time += destination;
    printf("%s has traveled through time and is now at %s\n", traveler->name, ctime(&(traveler->travel_time)));
}

int main() {
    TimeTraveler travelers[MAX_TIME_TRAVELERS];
    int i;

    for (i = 0; i < MAX_TIME_TRAVELERS; i++) {
        printf("Enter name for traveler %d: ", i + 1);
        scanf("%s", travelers[i].name);
        printf("Enter age for traveler %s: ", travelers[i].name);
        scanf("%d", &travelers[i].age);
        travelers[i].travel_time = time(NULL);
    }

    printf("\nCurrent travelers:\n");
    print_travelers(travelers);

    printf("\nChoose a traveler to send into the future: ");
    int traveler_index;
    scanf("%d", &traveler_index);

    TimeTraveler* traveler = &travelers[traveler_index - 1];

    printf("\nEnter the number of years you want to send %s into the future: ", traveler->name);
    int years_to_travel;
    scanf("%d", &years_to_travel);

    travel_in_time(traveler, years_to_travel * 31536000); // 31536000 seconds in a year

    printf("\nUpdated travelers:\n");
    print_travelers(travelers);

    return 0;
}