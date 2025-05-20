//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>

#define MAX_USERS 1000      // maximum number of users
#define MAX_LENGTH 50       // maximum length of username and password
#define MAX_TRACKERS 10     // maximum number of trackers per user
#define TRACKER_LENGTH 100  // length of the tracker data file

// user struct
typedef struct User {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    struct Tracker *trackers[MAX_TRACKERS];
    int num_trackers;
} User;

// tracker struct
typedef struct Tracker {
    char name[MAX_LENGTH];
    char data[TRACKER_LENGTH];
    struct tm date_created;
    struct tm last_updated;
} Tracker;

// function prototypes
void login(User *users, int num_users);
bool create_user(User *users, int *num_users, char *username, char *password);
bool create_tracker(User *user);
void delete_tracker(User *user);
void display_trackers(User *user);
void print_menu();
void save_data(User *users, int num_users);

int main() {
    int num_users = 0;
    User users[MAX_USERS];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    
    // load saved data
    FILE *fp = fopen("data.txt", "r");
    if(fp != NULL) {
        fread(users, sizeof(User), MAX_USERS, fp);
        fclose(fp);
    }
    
    while(true) {
        int choice;
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                // login
                login(users, num_users);
                break;
            case 2:
                // create user
                printf("Enter a username: ");
                scanf("%s", username);
                printf("Enter a password: ");
                scanf("%s", password);
                if(create_user(users, &num_users, username, password)) {
                    printf("User created successfully!\n");
                } else {
                    printf("Failed to create user.\n");
                }
                break;
            case 3:
                // save and quit
                save_data(users, num_users);
                printf("Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please enter a choice from the menu.\n");
                break;
        }
    }
    
    return 0;
}

void login(User *users, int num_users) {
    printf("Enter your username: ");
    char username[MAX_LENGTH];
    scanf("%s", username);
    printf("Enter your password: ");
    char password[MAX_LENGTH];
    scanf("%s", password);
    bool found = false;
    int index;
    for(int i=0; i<num_users; i++) {
        if(strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            found = true;
            index = i;
            break;
        }
    }
    if(found) {
        printf("Welcome %s!\n", username);
        while(true) {
            int choice;
            printf("1. Create tracker\n");
            printf("2. Delete tracker\n");
            printf("3. Display trackers\n");
            printf("4. Logout\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch(choice) {
                case 1:
                    // create tracker
                    if(create_tracker(&users[index])) {
                        printf("Tracker created successfully!\n");
                    } else {
                        printf("Failed to create tracker.\n");
                    }
                    break;
                case 2:
                    // delete tracker
                    delete_tracker(&users[index]);
                    break;
                case 3:
                    // display trackers
                    display_trackers(&users[index]);
                    break;
                case 4:
                    // logout
                    printf("Logging out.\n");
                    return;
                    break;
                default:
                    printf("Invalid choice. Please enter a choice from the menu.\n");
                    break;
            }
        }
    } else {
        printf("Invalid username or password.\n");
    }
}

bool create_user(User *users, int *num_users, char *username, char *password) {
    if(*num_users == MAX_USERS) {
        return false;
    }
    // check if username already exists
    for(int i=0; i<*num_users; i++) {
        if(strcmp(users[i].username, username) == 0) {
            return false;
        }
    }
    // create new user
    User new_user;
    strcpy(new_user.username, username);
    strcpy(new_user.password, password);
    new_user.num_trackers = 0;
    users[*num_users] = new_user;
    *num_users += 1;
    return true;
}

bool create_tracker(User *user) {
    if(user->num_trackers == MAX_TRACKERS) {
        return false;
    }
    Tracker new_tracker;
    printf("Enter a name for the tracker: ");
    scanf("%s", new_tracker.name);
    printf("Enter the tracker data (up to %d characters): ", TRACKER_LENGTH-1);
    scanf(" %[^\n]s", new_tracker.data);
    time_t raw_time;
    time(&raw_time);
    struct tm *time_info = localtime(&raw_time);
    new_tracker.date_created = *time_info;
    new_tracker.last_updated = *time_info;
    user->trackers[user->num_trackers] = malloc(sizeof(Tracker));
    *(user->trackers[user->num_trackers]) = new_tracker;
    user->num_trackers += 1;
    return true;
}

void delete_tracker(User *user) {
    if(user->num_trackers == 0) {
        printf("You do not have any trackers to delete.\n");
        return;
    }
    printf("Which tracker would you like to delete?\n");
    for(int i=0; i<user->num_trackers; i++) {
        printf("%d. %s (%d/%02d/%02d %02d:%02d:%02d)\n", i+1, user->trackers[i]->name,
        user->trackers[i]->last_updated.tm_year+1900, user->trackers[i]->last_updated.tm_mon+1,
        user->trackers[i]->last_updated.tm_mday, user->trackers[i]->last_updated.tm_hour,
        user->trackers[i]->last_updated.tm_min, user->trackers[i]->last_updated.tm_sec);
    }
    printf("Enter the number of the tracker you would like to delete: ");
    int choice;
    scanf("%d", &choice);
    if(choice < 1 || choice > user->num_trackers) {
        printf("Invalid choice.\n");
        return;
    }
    // free memory allocated for tracker
    free(user->trackers[choice-1]);
    // shift elements to fill in deleted tracker
    for(int i=choice-1; i<user->num_trackers-1; i++) {
        user->trackers[i] = user->trackers[i+1];
    }
    user->num_trackers -= 1;
    printf("Tracker deleted successfully!\n");
}

void display_trackers(User *user) {
    if(user->num_trackers == 0) {
        printf("You do not have any trackers to display.\n");
        return;
    }
    for(int i=0; i<user->num_trackers; i++) {
        printf("Tracker name: %s\n", user->trackers[i]->name);
        printf("Tracker data: %s\n", user->trackers[i]->data);
        printf("Date created: %d/%02d/%02d %02d:%02d:%02d\n", user->trackers[i]->date_created.tm_year+1900,
        user->trackers[i]->date_created.tm_mon+1, user->trackers[i]->date_created.tm_mday,
        user->trackers[i]->date_created.tm_hour, user->trackers[i]->date_created.tm_min,
        user->trackers[i]->date_created.tm_sec);
        printf("Last updated: %d/%02d/%02d %02d:%02d:%02d\n", user->trackers[i]->last_updated.tm_year+1900,
        user->trackers[i]->last_updated.tm_mon+1, user->trackers[i]->last_updated.tm_mday,
        user->trackers[i]->last_updated.tm_hour, user->trackers[i]->last_updated.tm_min,
        user->trackers[i]->last_updated.tm_sec);
    }
}

void print_menu() {
    printf("1. Login\n");
    printf("2. Create user\n");
    printf("3. Save and Quit\n");
}

void save_data(User *users, int num_users) {
    FILE *fp = fopen("data.txt", "w");
    fwrite(users, sizeof(User), num_users, fp);
    fclose(fp);
}