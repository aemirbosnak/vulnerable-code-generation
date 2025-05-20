//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: brave
#include <stdio.h>

/* Define struct for each workout session */
typedef struct{
    int pushups;
    int crunches;
    int squats;
    int lunges;
    int jumps;
} WorkoutSession;

int main(){
    /* Initialize variables */
    int sessions = 0;
    int totalPushups = 0;
    int totalCrunches = 0;
    int totalSquats = 0;
    int totalLunges = 0;
    int totalJumps = 0;

    printf("Welcome to the C Fitness Tracker!\n\n");

    /* Continue until user enters 0 */
    while(1){
        printf("Enter workout data for session %d (enter 0 to stop):", sessions+1);

        /* Initialize struct */
        WorkoutSession session = {0};

        /* Get input from user */
        scanf("%d %d %d %d %d", &session.pushups, &session.crunches, &session.squats, &session.lunges, &session.jumps);

        /* Break if user entered 0 for all inputs */
        if (session.pushups == 0 && session.crunches == 0 && session.squats == 0 && session.lunges == 0 && session.jumps == 0){
            break;
        }

        /* Add to totals */
        totalPushups += session.pushups;
        totalCrunches += session.crunches;
        totalSquats += session.squats;
        totalLunges += session.lunges;
        totalJumps += session.jumps;

        sessions++;
    }

    /* Print summary of workout data */
    printf("\n--- Workout Summary ---\n");
    printf("Total Sessions: %d\n", sessions);
    printf("Total Pushups: %d\n", totalPushups);
    printf("Total Crunches: %d\n", totalCrunches);
    printf("Total Squats: %d\n", totalSquats);
    printf("Total Lunges: %d\n", totalLunges);
    printf("Total Jumps: %d\n", totalJumps);

    return 0;
}