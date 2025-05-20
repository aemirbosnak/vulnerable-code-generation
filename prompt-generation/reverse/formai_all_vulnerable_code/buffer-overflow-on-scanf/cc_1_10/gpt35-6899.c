//FormAI DATASET v1.0 Category: System administration ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_USERS 100
#define MAX_RESERVATIONS_PER_USER 10

struct reservation {
  char date[20];
  char time[10];
};

struct user {
  int id;
  char username[50];
  char password[50];
  int num_reservations;
  struct reservation reservations[MAX_RESERVATIONS_PER_USER];
};

struct user users[MAX_USERS];
int num_users = 0;

void login() {
  char username[50];
  char password[50];
  printf("Username: ");
  scanf("%s", username);
  printf("Password: ");
  scanf("%s", password);

  int user_found = 0;

  for (int i = 0; i < num_users; i++) {
    if (strcmp(users[i].username, username) == 0 &&
        strcmp(users[i].password, password) == 0) {
      user_found = 1;

      printf("\nWelcome, %s!\n", username);

      int choice = -1;
      while (choice != 0) {
        printf("\n1. View Reservations\n");
        printf("2. Make Reservation\n");
        printf("3. Cancel Reservation\n");
        printf("0. Logout\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
          printf("\nYour Reservations:\n");

          if (users[i].num_reservations == 0) {
            printf("You have no reservations.\n");
          } else {
            for (int j = 0; j < users[i].num_reservations; j++) {
              printf("%d. %s at %s\n", j + 1, users[i].reservations[j].date,
                     users[i].reservations[j].time);
            }
          }
        } else if (choice == 2) {
          printf("\nEnter date (mm/dd/yyyy): ");
          char date[20];
          scanf("%s", date);
          printf("Enter time (hh:mm AM/PM): ");
          char time[10];
          scanf("%s", time);

          if (users[i].num_reservations == MAX_RESERVATIONS_PER_USER) {
            printf("\nSorry, you have reached the maximum number of reservations.\n");
          } else {
            users[i].reservations[users[i].num_reservations].date[0] = '\0';
            users[i].reservations[users[i].num_reservations].time[0] = '\0';
            strcpy(users[i].reservations[users[i].num_reservations].date, date);
            strcpy(users[i].reservations[users[i].num_reservations].time, time);
            users[i].num_reservations++;
            printf("\nReservation successful!\n");
          }
        } else if (choice == 3) {
          printf("\nEnter reservation number to cancel: ");
          int res_num;
          scanf("%d", &res_num);
          if (res_num <= 0 || res_num > users[i].num_reservations) {
            printf("\nInvalid reservation number.\n");
          } else {
            printf("\nCancelled reservation for %s at %s.\n",
                   users[i].reservations[res_num - 1].date,
                   users[i].reservations[res_num - 1].time);
            for (int j = res_num - 1; j < users[i].num_reservations - 1; j++) {
              users[i].reservations[j] = users[i].reservations[j + 1];
            }
            users[i].num_reservations--;
          }
        } else if (choice == 0) {
          printf("\nLogged out successfully.\n");
        } else {
          printf("\nInvalid choice.\n");
        }
      }
    }
  }

  if (!user_found) {
    printf("\nInvalid username or password.\n");
  }
}

void register_user() {
  char username[50];
  char password[50];
  printf("Enter desired username: ");
  scanf("%s", username);
  printf("Enter desired password: ");
  scanf("%s", password);

  if (num_users == MAX_USERS) {
    printf("\nSorry, the system has reached its maximum number of users.\n");
  } else {
    users[num_users].id = num_users;
    users[num_users].username[0] = '\0';
    users[num_users].password[0] = '\0';
    strcpy(users[num_users].username, username);
    strcpy(users[num_users].password, password);
    users[num_users].num_reservations = 0;
    printf("\nUser created successfully!\n");
    num_users++;
  }
}

int main(int argc, char *argv[]) {
  printf("==== Apocalypse Reservation System ====\n\n");
  int choice = -1;

  while (choice != 0) {
    printf("1. Login\n");
    printf("2. Register\n");
    printf("0. Exit\n");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
      login();
    } else if (choice == 2) {
      register_user();
    } else if (choice == 0) {
      printf("\nExiting the system...\n");
    } else {
      printf("\nInvalid choice.\n");
    }
  }

  return 0;
}