//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SESSIONS 100

struct WorkoutSession {
    double distance;
    double caloriesBurned;
    int duration;
    time_t date;
};

int sessionsCount = 0;
struct WorkoutSession sessions[MAX_SESSIONS];

void addSession(double distance, double caloriesBurned, int duration) {
    time_t now;
    time(&now);

    struct WorkoutSession session = {
        .distance = distance,
        .caloriesBurned = caloriesBurned,
        .duration = duration,
        .date = now
    };

    sessions[sessionsCount++] = session;
    printf("Session added successfully\n");
}

void viewSession(int sessionIndex) {
    struct WorkoutSession session = sessions[sessionIndex];

    printf("Session #%d\n", sessionIndex + 1);
    printf("  Date: %s", ctime(&session.date));
    printf("  Distance: %.2f miles\n", session.distance);
    printf("  Calories Burned: %.2f kcal\n", session.caloriesBurned);
    printf("  Duration: %d min\n", session.duration);
}

void viewAllSessions() {
    printf("All Sessions:\n");

    for (int i = 0; i < sessionsCount; i++) {
        viewSession(i);
    }
}

double getAverageDistance() {
    double totalDistance = 0;

    for (int i = 0; i < sessionsCount; i++) {
        totalDistance += sessions[i].distance;
    }

    return totalDistance / sessionsCount;
}

double getAverageCaloriesBurned() {
    double totalCaloriesBurned = 0;

    for (int i = 0; i < sessionsCount; i++) {
        totalCaloriesBurned += sessions[i].caloriesBurned;
    }

    return totalCaloriesBurned / sessionsCount;
}

int main() {
    int option = 0;

    do {
        printf("\nMenu:\n");
        printf("1. Add Workout Session\n");
        printf("2. View Single Workout Session\n");
        printf("3. View All Workout Sessions\n");
        printf("4. View Average Distance\n");
        printf("5. View Average Calories Burned\n");
        printf("6. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                double distance, caloriesBurned;
                int duration;

                printf("Enter Distance (miles): ");
                scanf("%lf", &distance);

                printf("Enter Calories Burned (kcal): ");
                scanf("%lf", &caloriesBurned);

                printf("Enter Duration (min): ");
                scanf("%d", &duration);

                addSession(distance, caloriesBurned, duration);

                break;
            }
            case 2: {
                int sessionIndex;

                printf("Enter Session Index (1-%d): ", sessionsCount);
                scanf("%d", &sessionIndex);

                if (sessionIndex < 1 || sessionIndex > sessionsCount) {
                    printf("Invalid Session Index\n");
                } else {
                    viewSession(sessionIndex - 1);
                }

                break;
            }
            case 3: {
                viewAllSessions();

                break;
            }
            case 4: {
                double averageDistance = getAverageDistance();
                printf("Average Distance: %.2f miles\n", averageDistance);

                break;
            }
            case 5: {
                double averageCaloriesBurned = getAverageCaloriesBurned();
                printf("Average Calories Burned: %.2f kcal\n", averageCaloriesBurned);

                break;
            }
            case 6: {
                printf("Goodbye!\n");

                break;
            }
            default: {
                printf("Invalid Option\n");
            }
        }
    } while (option != 6);

    return 0;
}