//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_MEMBERS 100
#define NAME_LENGTH 30
#define EMAIL_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
} Member;

typedef struct {
    Member members[MAX_MEMBERS];
    int member_count;
    pthread_mutex_t mutex;
} MailingList;

MailingList *createMailingList() {
    MailingList *list = malloc(sizeof(MailingList));
    if (!list) {
        fprintf(stderr, "Memory allocation failed! Exiting...\n");
        exit(EXIT_FAILURE);
    }
    list->member_count = 0;
    pthread_mutex_init(&list->mutex, NULL);
    return list;
}

void addMember(MailingList *list, const char *name, const char *email) {
    pthread_mutex_lock(&list->mutex);
    if (list->member_count >= MAX_MEMBERS) {
        fprintf(stderr, "Maximum members reached! Can't add more.\n");
        pthread_mutex_unlock(&list->mutex);
        return;
    }

    for (int i = 0; i < list->member_count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            fprintf(stderr, "Email %s already exists! Not adding.\n", email);
            pthread_mutex_unlock(&list->mutex);
            return;
        }
    }

    strncpy(list->members[list->member_count].name, name, NAME_LENGTH - 1);
    strncpy(list->members[list->member_count].email, email, EMAIL_LENGTH - 1);
    list->members[list->member_count].name[NAME_LENGTH - 1] = '\0';
    list->members[list->member_count].email[EMAIL_LENGTH - 1] = '\0';
    
    list->member_count++;
    printf("Member %s added successfully!\n", name);
    pthread_mutex_unlock(&list->mutex);
}

void removeMember(MailingList *list, const char *email) {
    pthread_mutex_lock(&list->mutex);
    for (int i = 0; i < list->member_count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            // Move last member into current position
            list->members[i] = list->members[list->member_count - 1];
            list->member_count--;
            printf("Member with email %s removed successfully!\n", email);
            pthread_mutex_unlock(&list->mutex);
            return;
        }
    }
    printf("Could not find member with email %s.\n", email);
    pthread_mutex_unlock(&list->mutex);
}

void listMembers(MailingList *list) {
    pthread_mutex_lock(&list->mutex);
    if (list->member_count == 0) {
        printf("No members in the mailing list.\n");
    } else {
        printf("Mailing List Members:\n");
        for (int i = 0; i < list->member_count; i++) {
            printf("Name: %s, Email: %s\n", list->members[i].name, list->members[i].email);
        }
    }
    pthread_mutex_unlock(&list->mutex);
}

void freeMailingList(MailingList *list) {
    pthread_mutex_destroy(&list->mutex);
    free(list);
}

void *inputThread(void *arg) {
    MailingList *list = (MailingList *)arg;
    char command[100], name[NAME_LENGTH], email[EMAIL_LENGTH];

    while (1) {
        printf("\nEnter command (add/remove/list/exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter email: ");
            scanf("%s", email);
            addMember(list, name, email);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter email to remove: ");
            scanf("%s", email);
            removeMember(list, email);
        } else if (strcmp(command, "list") == 0) {
            listMembers(list);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Unknown command! Please try again.\n");
        }
    }
    return NULL;
}

int main() {
    MailingList *list = createMailingList();
    
    pthread_t thread;
    pthread_create(&thread, NULL, inputThread, (void *)list);
    pthread_join(thread, NULL);
    
    freeMailingList(list);
    return 0;
}