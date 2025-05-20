//FormAI DATASET v1.0 Category: Email Client ; Style: minimalist
#define MAX_MESSAGES 100

typedef struct {
    char* sender;
    char* subject;
    char* body;
} Email;

Email inbox[MAX_MESSAGES];

int main() {
    int num_messages = 0;

    while (1) {
        printf("1. Compose Email\n");
        printf("2. View Inbox\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter Sender: ");
            char* sender = malloc(50);
            scanf("%s", sender);

            printf("Enter Subject: ");
            char* subject = malloc(50);
            scanf("%s", subject);

            printf("Enter Body: ");
            char* body = malloc(500);
            scanf("%s", subject);

            Email new_email = {sender, subject, body};
            inbox[num_messages++] = new_email;

            printf("Email Sent!\n");

        } else if (choice == 2) {
            printf("Inbox:\n");

            if (num_messages == 0) {
                printf("No messages to display.\n");
            } else {
                for (int i = 0; i < num_messages; i++) {
                    printf("%d. From: %s\n", i+1, inbox[i].sender);
                    printf("   Subject: %s\n", inbox[i].subject);
                    printf("   Message: %s\n", inbox[i].body);
                }
            }

        } else if (choice == 3) {
            printf("Goodbye!\n");
            return 0;
        }
    }
}