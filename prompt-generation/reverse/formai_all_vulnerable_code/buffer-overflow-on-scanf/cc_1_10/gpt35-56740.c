//FormAI DATASET v1.0 Category: Mailing list manager ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

struct MailingList {
    char name[100];
    char email[100];
    int id;
};

struct MailingList emailList[100];
int numEmails = 0;

pthread_mutex_t lock;

void *addEmail(void *arg);
void *removeEmail(void *arg);

int main() {
    pthread_t addThread, removeThread;
    int addError, removeError;

    pthread_mutex_init(&lock, NULL);

    addError = pthread_create(&addThread, NULL, addEmail, NULL);
    if (addError) {
        printf("Error creating adding thread: %d\n", addError);
        exit(-1);
    }

    removeError = pthread_create(&removeThread, NULL, removeEmail, NULL);
    if (removeError) {
        printf("Error creating removing thread: %d\n", removeError);
        exit(-1);
    }

    pthread_join(addThread, NULL);
    pthread_join(removeThread, NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}

void *addEmail(void *arg) {
    while (1) {
        pthread_mutex_lock(&lock);
        char name[100], email[100];
        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter email: ");
        scanf("%s", email);

        struct MailingList newEmail;
        strcpy(newEmail.name, name);
        strcpy(newEmail.email, email);
        newEmail.id = numEmails;

        emailList[numEmails++] = newEmail;

        printf("Added %s to the email list\n", email);

        sleep(1);

        pthread_mutex_unlock(&lock);
    }
}

void *removeEmail(void *arg) {
    while (1) {
        pthread_mutex_lock(&lock);

        if (numEmails == 0) {
            printf("No emails to remove\n");
        } else {
            int idToRemove;
            printf("Enter ID of email to remove: ");
            scanf("%d", &idToRemove);

            int indexToRemove = -1;
            for (int i = 0; i < numEmails; i++) {
                if (emailList[i].id == idToRemove) {
                    indexToRemove = i;
                    break;
                }
            }

            if (indexToRemove == -1) {
                printf("ID %d not found in the email list\n", idToRemove);
            } else {
                printf("Removing %s from the email list\n", emailList[indexToRemove].email);

                for (int i = indexToRemove; i < numEmails - 1; i++) {
                    emailList[i] = emailList[i + 1];
                }
                numEmails--;
            }
        }

        sleep(1);

        pthread_mutex_unlock(&lock);
    }
}