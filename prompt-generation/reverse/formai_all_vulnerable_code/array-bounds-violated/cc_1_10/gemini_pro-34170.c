//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Feeling a bit bubbly today? Let's jazz up our exam system!

// A vibrant palette to color our choices
enum Color {
    BLUSH_PINK,
    SUNFLOWER_YELLOW,
    OCEAN_BLUE,
    LEAFY_GREEN,
    VIOLET_PURPLE
};

// Our cheerful candidates
struct Candidate {
    char name[100];
    int score;
    enum Color favorite_color;
};

// The grand finale - our sparkling exam paper
void exam() {
    // Welcome our eager students
    printf("Hello, bright sparks! Welcome to our cheerful exam.\n");

    // Create a dazzling array of candidates
    struct Candidate candidates[] = {
        {"Ally", 90, OCEAN_BLUE},
        {"Bob", 80, SUNFLOWER_YELLOW},
        {"Cindy", 100, BLUSH_PINK},
        {"David", 70, LEAFY_GREEN},
        {"Emily", 85, VIOLET_PURPLE}
    };

    // Let's shuffle the questions, adding a touch of excitement
    int num_questions = 10;
    int questions[num_questions];
    for (int i = 0; i < num_questions; i++) {
        questions[i] = i;
    }
    for (int i = 0; i < num_questions; i++) {
        int j = rand() % num_questions;
        int temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }

    // Now, let the exam commence!
    printf("Time to showcase your brilliance!\n");
    for (int i = 0; i < num_questions; i++) {
        // Display the question with a sprinkle of whimsy
        printf("Question %d: Why is the sky blue? (a) Fairies love blue, (b) Rainbows reflect, (c) Light scattering\n", questions[i] + 1);
        int answer;
        scanf("%d", &answer);
        if (answer == 3) {
            candidates[i].score += 10;
            printf("Yay! You're a ray of sunshine!\n");
        }
    }

    // Time to unveil the stars of the show
    printf("Drumroll, please! Here are our top performers:\n");
    for (int i = 0; i < 5; i++) {
        int max_score = 0;
        int max_index = 0;
        for (int j = 0; j < 5; j++) {
            if (candidates[j].score > max_score) {
                max_score = candidates[j].score;
                max_index = j;
            }
        }
        printf("%d. %s (%d) - Favorite color: ", i + 1, candidates[max_index].name, candidates[max_index].score);
        switch (candidates[max_index].favorite_color) {
            case BLUSH_PINK:
                printf("Blush Pink - Oh, so sweet!\n");
                break;
            case SUNFLOWER_YELLOW:
                printf("Sunflower Yellow - Bright and cheerful!\n");
                break;
            case OCEAN_BLUE:
                printf("Ocean Blue - Deep and dreamy!\n");
                break;
            case LEAFY_GREEN:
                printf("Leafy Green - Earthy and refreshing!\n");
                break;
            case VIOLET_PURPLE:
                printf("Violet Purple - Mysterious and enchanting!\n");
                break;
        }
        candidates[max_index].score = 0;
    }

    // A round of applause for all our participants
    printf("Congratulations to our brilliant candidates! May your knowledge continue to shine.\n");
}

int main() {
    // Set the stage for our lively exam
    exam();
    return 0;
}