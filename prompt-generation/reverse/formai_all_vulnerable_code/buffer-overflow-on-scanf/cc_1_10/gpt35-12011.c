//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRAINING_SESSIONS 30
#define MAX_EXERCISES_PER_SESSION 10
#define MAX_NAME_LENGTH 50

// Exercise struct
typedef struct Exercise {
    char name[MAX_NAME_LENGTH];
    int reps;
    int sets;
} Exercise;

// Training Session struct
typedef struct TrainingSession {
    Exercise exercises[MAX_EXERCISES_PER_SESSION];
    int numExercises;
    struct tm sessionDate;
} TrainingSession;

// Fitness Tracker struct
typedef struct FitnessTracker {
    TrainingSession sessions[MAX_TRAINING_SESSIONS];
    int numSessions;
} FitnessTracker;

// Function prototypes
void displayMenu();
void addTrainingSession(FitnessTracker *tracker);
void listTrainingSessions(FitnessTracker *tracker);
void deleteTrainingSession(FitnessTracker *tracker);
void searchTrainingSession(FitnessTracker *tracker);
int compareDates(struct tm d1, struct tm d2);

// Main function
int main() {
    FitnessTracker tracker;
    tracker.numSessions = 0;
    
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addTrainingSession(&tracker);
                break;
            case 2:
                listTrainingSessions(&tracker);
                break;
            case 3:
                deleteTrainingSession(&tracker);
                break;
            case 4:
                searchTrainingSession(&tracker);
                break;
            case 5:
                printf("Thank you for using the Fitness Tracker!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while(choice != 5);

    return 0;
}

// Displays menu options
void displayMenu() {
    printf("\n Fitness Tracker\n");
    printf("------------------\n");
    printf("1. Add new training session\n");
    printf("2. List all training sessions\n");
    printf("3. Delete training session\n");
    printf("4. Search for training session\n");
    printf("5. Exit\n");
    printf("------------------\n");
    printf("Enter your choice: ");
}

// Adds a new training session to the tracker
void addTrainingSession(FitnessTracker *tracker) {
    // Check if tracker is full
    if(tracker->numSessions == MAX_TRAINING_SESSIONS) {
        printf("Fitness tracker is full, cannot add new session.\n");
        return;
    }

    TrainingSession session;

    // Get session date from user
    int day, month, year;
    printf("Enter session date (DD MM YYYY): ");
    scanf("%d %d %d", &day, &month, &year);

    session.sessionDate.tm_mday = day;
    session.sessionDate.tm_mon = month - 1;
    session.sessionDate.tm_year = year - 1900;

    // Get exercises
    char name[MAX_NAME_LENGTH];
    int reps, sets;
    int i = 0;

    do {
        printf("Enter exercise (name reps sets) or type 'exit' to finish: ");
        scanf("%s", name);

        if(strcmp(name, "exit") == 0) {
            break;
        }

        scanf("%d %d", &reps, &sets);

        strcpy(session.exercises[i].name, name);
        session.exercises[i].reps = reps;
        session.exercises[i].sets = sets;

        i++;

    } while(i < MAX_EXERCISES_PER_SESSION);

    session.numExercises = i;

    tracker->sessions[tracker->numSessions++] = session;

    printf("Training session added successfully!\n");

}

// Lists all training sessions
void listTrainingSessions(FitnessTracker *tracker) {
    // Check if tracker is empty
    if(tracker->numSessions == 0) {
        printf("Fitness tracker is empty, no sessions to display.\n");
        return;
    }

    // Sort sessions by date
    TrainingSession sortedSessions[MAX_TRAINING_SESSIONS];
    memcpy(sortedSessions, tracker->sessions, sizeof(TrainingSession) * tracker->numSessions);

    for(int i = 0; i < tracker->numSessions; i++) {
        for(int j = i + 1; j < tracker->numSessions; j++) {
            if(compareDates(sortedSessions[i].sessionDate, sortedSessions[j].sessionDate) > 0) {
                TrainingSession temp = sortedSessions[i];
                sortedSessions[i] = sortedSessions[j];
                sortedSessions[j] = temp;
            }
        }
    }

    printf("Session Date | Exercise Name | Reps | Sets \n");

    for(int i = 0; i < tracker->numSessions; i++) {
        printf("%02d/%02d/%4d  | ", sortedSessions[i].sessionDate.tm_mday, sortedSessions[i].sessionDate.tm_mon + 1, sortedSessions[i].sessionDate.tm_year + 1900);

        for(int j = 0; j < sortedSessions[i].numExercises; j++) {
            if(j > 0) {
                printf("              ");
            }

            printf("%s | %d | %d \n", sortedSessions[i].exercises[j].name, sortedSessions[i].exercises[j].reps, sortedSessions[i].exercises[j].sets);
        }
    }
}

// Deletes a training session
void deleteTrainingSession(FitnessTracker *tracker) {
    // Check if tracker is empty
    if(tracker->numSessions == 0) {
        printf("Fitness tracker is empty, no sessions to delete.\n");
        return;
    }

    int day, month, year;
    printf("Enter session date to delete (DD MM YYYY): ");
    scanf("%d %d %d", &day, &month, &year);

    struct tm deleteDate;
    deleteDate.tm_mday = day;
    deleteDate.tm_mon = month - 1;
    deleteDate.tm_year = year - 1900;

    int deleteIndex = -1;
    for(int i = 0; i < tracker->numSessions; i++) {
        if(compareDates(tracker->sessions[i].sessionDate, deleteDate) == 0) {
            deleteIndex = i;
            break;
        }
    }

    if(deleteIndex == -1) {
        printf("No session found on the specified date.\n");
        return;
    }

    for(int i = deleteIndex; i < tracker->numSessions - 1; i++) {
        tracker->sessions[i] = tracker->sessions[i+1];
    }

    tracker->numSessions--;

    printf("Training session deleted successfully!\n");
}

// Search for a training session by date
void searchTrainingSession(FitnessTracker *tracker) {
    // Check if tracker is empty
    if(tracker->numSessions == 0) {
        printf("Fitness tracker is empty, no sessions to search.\n");
        return;
    }

    int day, month, year;
    printf("Enter session date to search (DD MM YYYY): ");
    scanf("%d %d %d", &day, &month, &year);

    struct tm searchDate;
    searchDate.tm_mday = day;
    searchDate.tm_mon = month - 1;
    searchDate.tm_year = year - 1900;

    for(int i = 0; i < tracker->numSessions; i++) {
        if(compareDates(tracker->sessions[i].sessionDate, searchDate) == 0) {
            printf("Session Date | Exercise Name | Reps | Sets \n");
            printf("%02d/%02d/%4d  | ", tracker->sessions[i].sessionDate.tm_mday, tracker->sessions[i].sessionDate.tm_mon + 1, tracker->sessions[i].sessionDate.tm_year + 1900);

            for(int j = 0; j < tracker->sessions[i].numExercises; j++) {
                if(j > 0) {
                    printf("              ");
                }

                printf("%s | %d | %d \n", tracker->sessions[i].exercises[j].name, tracker->sessions[i].exercises[j].reps, tracker->sessions[i].exercises[j].sets);
            }

            return;
        }
    }

    printf("No session found on the specified date.\n");
}

// Utility function to compare two dates
int compareDates(struct tm d1, struct tm d2) {
   if(d1.tm_year < d2.tm_year)
      return -1;
   else if(d1.tm_year > d2.tm_year)
      return 1;

   if(d1.tm_mon < d2.tm_mon)
      return -1;
   else if(d1.tm_mon > d2.tm_mon)
      return 1;

   if(d1.tm_mday < d2.tm_mday)
      return -1;
   else if(d1.tm_mday > d2.tm_mday)
      return 1;

   return 0;
}