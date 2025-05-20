//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MAX_USERS 100
#define MAX_MESSAGES 1000

typedef struct user_info {
    char name[50];
    int messages_received;
} UserInfo;

typedef struct message_info {
    char content[100];
    int sender;
    int receiver;
} MessageInfo;

int main() {
    int num_users, num_messages;

    printf("Enter the number of users: ");
    scanf("%d", &num_users);
    printf("Enter the number of messages: ");
    scanf("%d", &num_messages);

    UserInfo* users = (UserInfo*)malloc(num_users * sizeof(UserInfo));
    MessageInfo* messages = (MessageInfo*)malloc(num_messages * sizeof(MessageInfo));

    for (int i = 0; i < num_users; i++) {
        printf("Enter user name: ");
        scanf("%s", users[i].name);
    }

    for (int i = 0; i < num_messages; i++) {
        printf("Enter message content: ");
        scanf("%s", messages[i].content);
    }

    for (int i = 0; i < num_users; i++) {
        for (int j = 0; j < num_messages; j++) {
            if (users[i].name == messages[j].sender) {
                users[i].messages_received++;
                printf("User %s received a message from %s\n", users[i].name, messages[j].sender);
            }
            if (users[i].name == messages[j].receiver) {
                users[i].messages_received++;
                printf("User %s received a message from %s\n", users[i].name, messages[j].sender);
            }
        }
    }

    free(users);
    free(messages);

    return 0;
}