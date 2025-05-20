//FormAI DATASET v1.0 Category: Email Client ; Style: Ken Thompson
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>

#define BUFSIZE 1024
#define MAXATTACHMENTS 5

void sendmail(char* to, char* subject, char* body, char *file_uploads[], int num_uploads) {

    char command[BUFSIZE];
    int i;

    for (i=0; i<num_uploads; i++) {
        sprintf(command, "uuencode %s %s >> /tmp/mail_body", file_uploads[i], file_uploads[i]);
        system(command);
    }

    sprintf(command, "echo \"To: %s\nSubject: %s\n\" > /tmp/mail", to, subject);
    system(command);

    sprintf(command, "cat /tmp/mail /tmp/mail_body > /tmp/mail_final");
    system(command);

    sprintf(command, "cat /tmp/mail_final | sendmail -t ");
    system(command);

    sprintf(command, "rm /tmp/mail*");
    system(command);

}

int main(int argc, char* argv[]) {

    char to[BUFSIZE], subject[BUFSIZE], body[BUFSIZE], *file_uploads[MAXATTACHMENTS];
    int num_uploads=0, i;

    printf("To: ");
    fgets(to, BUFSIZE, stdin);
    printf("Subject: ");
    fgets(subject, BUFSIZE, stdin);
    printf("Body: ");
    fgets(body, BUFSIZE, stdin);

    while (1) {
        printf("Attach File (y/n)? ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'n') {
            break;
        }

        printf("Enter filename: ");
        char filename[BUFSIZE];
        scanf("%s", filename);

        file_uploads[num_uploads++] = (char*) malloc(BUFSIZE*sizeof(char));
        sprintf(file_uploads[num_uploads-1], "%s", filename);

        if (num_uploads >= MAXATTACHMENTS) {
            printf("Maximum attachments reached (%d)\n", MAXATTACHMENTS);
            break;
        }

    }

    sendmail(to, subject, body, file_uploads, num_uploads);

    for (i=0; i<num_uploads; i++) {
        free(file_uploads[i]);
    }
    
    return 0;
}