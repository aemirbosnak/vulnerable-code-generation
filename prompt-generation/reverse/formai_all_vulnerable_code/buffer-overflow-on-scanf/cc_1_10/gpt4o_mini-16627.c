//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int steps;
    float distance;  // in kilometers
    float calories;  // in kCal
    char mood[20];
} FitnessData;

void welcome_message() {
    printf("Welcome to the Surrealist Fitness Tracker!\n");
    printf("Here, numbers dance with words, and dreams take a step!\n");
    printf("Let's track the invisible footprints of your day!\n\n");
}

void capture_fitness_data(FitnessData *data) {
    printf("How many steps have you traversed through the fields of time today? ");
    scanf("%d", &data->steps);
    
    printf("In your journey, how far in kilometers do the shadows stretch? ");
    scanf("%f", &data->distance);
    
    printf("How many calories have you conjured from the ether? ");
    scanf("%f", &data->calories);
    
    printf("In the theater of your mind, what mood shimmers like a butterfly? ");
    scanf("%s", data->mood);
}

void display_fitness_data(FitnessData data) {
    printf("\n=== Your Surreal Fitness Journey ===\n");
    printf("Steps taken: %d\n", data.steps);
    printf("Distance traveled: %.2f km\n", data.distance);
    printf("Calories burned: %.2f kCal\n", data.calories);
    printf("Your current mood: %s\n", data.mood);
}

void save_to_file(FitnessData data) {
    FILE *file = fopen("fitness_data.txt", "a");
    if (!file) {
        printf("The quill could not touch the parchment...\n");
        return;
    }
    fprintf(file, "%d,%f,%f,%s\n", data.steps, data.distance, data.calories, data.mood);
    fclose(file);
    printf("Your essence has been penned into the annals of time!\n");
}

void generate_random_data(FitnessData *data) {
    data->steps = rand() % 10000;
    data->distance = (float)(rand() % 10000) / 1000;
    data->calories = (float)(rand() % 500);
    const char *moods[] = {"Joyful", "Melancholic", "Euphoric", "Pensive", "Ecstatic"};
    strcpy(data->mood, moods[rand() % 5]);
}

void ponder_the_meaning_of_fitness(FitnessData data) {
    printf("\nBeneath the clock's hands, we marvel at the essence:\n");
    printf("For every step, an echo in the cosmos...\n");
    if (data.steps < 1000) {
        printf("Your journey has just begun, as a seed in the soil.\n");
    } else if (data.steps < 5000) {
        printf("A path carved through clouds, the potential blooms in the air.\n");
    } else {
        printf("A marathon of thoughts, a symphony of footsteps!\n");
    }
}

int main() {
    srand(time(0));
    FitnessData today_data;
    welcome_message();
    
    char choice;
    while (1) {
        printf("\nChoose your path:\n");
        printf("1. Input my fitness data\n");
        printf("2. Generate random data\n");
        printf("3. Display my fitness data\n");
        printf("4. Save data to file\n");
        printf("5. Ponder the meaning of fitness\n");
        printf("6. Exit the tapestry of time\n");
        printf("Enter your choice (1-6): ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case '1':
                capture_fitness_data(&today_data);
                break;
            case '2':
                generate_random_data(&today_data);
                printf("Random data has emerged from the shadows of possibility!\n");
                break;
            case '3':
                display_fitness_data(today_data);
                break;
            case '4':
                save_to_file(today_data);
                break;
            case '5':
                ponder_the_meaning_of_fitness(today_data);
                break;
            case '6':
                printf("With a gentle sigh, we part ways...\n");
                exit(0);
            default:
                printf("A confusion in the cosmos... please choose again.\n");
        }
    }
    return 0;
}