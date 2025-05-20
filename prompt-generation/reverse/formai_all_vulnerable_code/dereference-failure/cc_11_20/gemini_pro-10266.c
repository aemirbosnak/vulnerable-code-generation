//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: retro
// Welcome to the POP3 Client Clubhouse! Grab some punch and get ready for some retro POP3 action.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Our very own POP3 commands. Feel free to add more if you're feeling adventurous!
#define RETR "RETR"
#define DELE "DELE"
#define RSET "RSET"
#define QUIT "QUIT"

// A dash of color to brighten up our terminal experience.
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

// Let's get this party started!
int main(int argc, char *argv[]) {
  // Check if we have the right number of arguments. If not, let's give them a gentle reminder.
  if (argc != 3) {
    printf(RED "Whoops! You've got the wrong number of arguments, pal. Try again with the server's IP address and port number.\n" RESET);
    return 1;
  }

  // Time to connect to the server. Let's hope they're expecting us!
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf(RED "Darn it! Couldn't connect to the server. Bummer.\n" RESET);
    return 1;
  }

  // Let's fill out the server's address so we know where to find them.
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(atoi(argv[2]));
  if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
    printf(RED "Oops! Couldn't understand that server address. Try again with a valid IP address.\n" RESET);
    return 1;
  }

  // And now, the moment we've all been waiting for... the connection!
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    printf(RED "Darn it! Couldn't connect to the server. Bummer.\n" RESET);
    return 1;
  }

  // Let's say hello to our server and see if they're ready to chat.
  char buffer[1024];
  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer), 0) <= 0) {
    printf(RED "Hmm... the server isn't responding. Are they taking a nap?\n" RESET);
    return 1;
  }
  printf(GRN "%s" RESET, buffer);

  // Let's send our commands and see what the server has to say.
  char command[1024];
  while (1) {
    printf(BLU "> " RESET);
    memset(command, 0, sizeof(command));
    scanf("%s", command);

    // Quitting time? Let's say goodbye and close up shop.
    if (!strcmp(command, QUIT)) {
      send(sockfd, QUIT, strlen(QUIT), 0);
      break;
    }

    // Fetching an email?
    else if (!strcmp(command, RETR)) {
      printf(YEL "Which email would you like to read, my friend? Enter the message number: " RESET);
      int msg_num;
      scanf("%d", &msg_num);
      sprintf(command, "%s %d\r\n", RETR, msg_num);
      send(sockfd, command, strlen(command), 0);

      // Let's see what the server sends back.
      memset(buffer, 0, sizeof(buffer));
      if (recv(sockfd, buffer, sizeof(buffer), 0) <= 0) {
        printf(RED "Hmm... the server isn't responding. Are they taking a nap?\n" RESET);
        continue;
      }
      printf(WHT "%s" RESET, buffer);
    }

    // Deleting an email?
    else if (!strcmp(command, DELE)) {
      printf(MAG "Which email would you like to delete, my friend? Enter the message number: " RESET);
      int msg_num;
      scanf("%d", &msg_num);
      sprintf(command, "%s %d\r\n", DELE, msg_num);
      send(sockfd, command, strlen(command), 0);

      // Let's see what the server says.
      memset(buffer, 0, sizeof(buffer));
      if (recv(sockfd, buffer, sizeof(buffer), 0) <= 0) {
        printf(RED "Hmm... the server isn't responding. Are they taking a nap?\n" RESET);
        continue;
      }
      printf(CYN "%s" RESET, buffer);
    }

    // Resetting the email list?
    else if (!strcmp(command, RSET)) {
      send(sockfd, RSET, strlen(RSET), 0);
      memset(buffer, 0, sizeof(buffer));
      if (recv(sockfd, buffer, sizeof(buffer), 0) <= 0) {
        printf(RED "Hmm... the server isn't responding. Are they taking a nap?\n" RESET);
        continue;
      }
      printf(GRN "%s" RESET, buffer);
    }

    // Not a valid command? Let's give them a friendly reminder.
    else {
      printf(RED "Hmm... I don't recognize that command, pal. Try again with a valid command.\n" RESET);
    }
  }

  // Time to wrap things up and say farewell to the server.
  close(sockfd);
  printf(BLU "Later, gator! Thanks for popping by." RESET "\n");
  return 0;
}