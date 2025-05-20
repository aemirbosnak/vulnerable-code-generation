//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: medieval
// AYE, A MAILING LIST MANAGER IN THE MEDIEVAL TONGUE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Serf {
   char *name;
   char *email;
} Serf;

Serf *serfdom[100]; // A ROSTER OF OUR LOYAL SUBJECTS
int numSerfs = 0;     // THE NUMBER OF SERFS IN OUR THRALL

void addSerf(char *name, char *email) {
   serfdom[numSerfs] = malloc(sizeof(Serf));
   serfdom[numSerfs]->name = strdup(name);
   serfdom[numSerfs]->email = strdup(email);
   numSerfs++;
}

void removeSerf(char *name) {
   int i;

   for (i = 0; i < numSerfs; i++) {
      if (strcmp(name, serfdom[i]->name) == 0) {
         free(serfdom[i]->name);
         free(serfdom[i]->email);
         free(serfdom[i]);
         numSerfs--;
         break;
      }
   }
}

void listSerfs() {
   int i;

   printf("Our loyal serfs:\n");
   for (i = 0; i < numSerfs; i++) {
      printf("%s <%s>\n", serfdom[i]->name, serfdom[i]->email);
   }
}

void sendMissive(char *subject, char *body) {
   int i;

   printf("Sending missive '%s':\n\n", subject);
   printf("%s\n\n", body);

   for (i = 0; i < numSerfs; i++) {
      printf("To: %s <%s>\n", serfdom[i]->name, serfdom[i]->email);
   }
}

int main(int argc, char *argv[]) {
   char command[80];

   while (1) {
      printf("> ");
      scanf("%s", command);

      if (strcmp(command, "quit") == 0) {
         break;
      } else if (strcmp(command, "add") == 0) {
         char name[80], email[80];

         printf("Name: ");
         scanf("%s", name);
         printf("Email: ");
         scanf("%s", email);

         addSerf(name, email);
      } else if (strcmp(command, "remove") == 0) {
         char name[80];

         printf("Name: ");
         scanf("%s", name);

         removeSerf(name);
      } else if (strcmp(command, "list") == 0) {
         listSerfs();
      } else if (strcmp(command, "send") == 0) {
         char subject[80], body[256];

         printf("Subject: ");
         scanf("%s", subject);
         printf("Body: ");
         scanf("%[^\n]", body);

         sendMissive(subject, body);
      } else {
         printf("Unknown command '%s'\n", command);
      }
   }

   return 0;
}