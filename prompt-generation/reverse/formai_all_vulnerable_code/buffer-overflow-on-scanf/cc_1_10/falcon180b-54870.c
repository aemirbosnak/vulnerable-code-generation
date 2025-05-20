//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: light-weight
#include <stdio.h>

// Function to print the movie ratings
void print_ratings(int ratings[]) {
    int i;
    for (i = 0; i < 5; i++) {
        printf("Rating %d: %d stars\n", i + 1, ratings[i]);
    }
}

// Function to get user ratings
int get_user_ratings() {
    int ratings[5];
    printf("Please rate the following aspects of the movie:\n");
    printf("1. Plot\n2. Acting\n3. Cinematography\n4. Soundtrack\n5. Overall experience\n");
    printf("Enter your ratings (1-5 stars): ");
    scanf("%d %d %d %d %d", &ratings[0], &ratings[1], &ratings[2], &ratings[3], &ratings[4]);
    return ratings[0] + ratings[1] + ratings[2] + ratings[3] + ratings[4];
}

// Function to get critic ratings
int get_critic_ratings() {
    int ratings[5];
    printf("Critic's ratings:\n");
    printf("1. Plot: %d stars\n", ratings[0] = 4);
    printf("2. Acting: %d stars\n", ratings[1] = 3);
    printf("3. Cinematography: %d stars\n", ratings[2] = 4);
    printf("4. Soundtrack: %d stars\n", ratings[3] = 3);
    printf("5. Overall experience: %d stars\n", ratings[4] = 4);
    return ratings[0] + ratings[1] + ratings[2] + ratings[3] + ratings[4];
}

// Function to calculate the average rating
float calculate_average_rating(int ratings[]) {
    int sum = 0;
    int i;
    for (i = 0; i < 5; i++) {
        sum += ratings[i];
    }
    return (float) sum / 5;
}

// Main function
int main() {
    int user_ratings = get_user_ratings();
    int critic_ratings = get_critic_ratings();
    int final_ratings[5];
    int i;
    for (i = 0; i < 5; i++) {
        final_ratings[i] = (user_ratings + critic_ratings) / 2;
    }
    float average_rating = calculate_average_rating(final_ratings);
    printf("Average rating: %.2f stars\n", average_rating);
    print_ratings(final_ratings);
    return 0;
}