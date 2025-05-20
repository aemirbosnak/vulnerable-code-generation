//FormAI DATASET v1.0 Category: Email Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() { 

//Initial setup
printf("Welcome to the C Email Client - a mystery to solve!\n\n");

printf("I peered at my computer screen: \"Please enter your email address\".\nMy, my! I was intrigued.\n");
char email[50];
scanf("%s", email);
printf("\n");

printf("\"Good day, %s. Please enter your email password.\"\n", email);
char password[50];
scanf("%s", password);
printf("\n");

//Listing emails
printf("\"Now, let me see what we have here...\"\n");
char mails[3][100] = {"From: Mary <mary@example.com>\nSubject: Invitation to a tea party\nContent: Dear Sir, I hope this email finds you in good spirits. I hope to see you soon at our annual tea party at 221B Baker Street.\"\n",
                      "From: John <john@example.com>\nSubject: Case update\nContent: The case is getting complicated, we have identified two more suspects. Get in touch with me at your earliest convenience.\"\n",
                      "From: Irene <irene@example.com>\nSubject: Missing gemstone\nContent: Hello detective, I beg of you to help me find my missing gemstone. I am convinced that it has been stolen and I have no idea who might have taken it.\"\n"};

for(int i=0; i<3; i++){
  printf("%s", mails[i]);
}

//Email selection
printf("\n\"Which email would you like to read, %s? Please enter the number (1-3)\"\n", email);
int selection; 
scanf("%d", &selection);

printf("\n\"Ah yes, let me retrieve that for you...\"\n\n");

printf("%s", mails[selection-1]);

//Email reply
printf("\"Would you like to reply to this email, Detective?\"\n Please type 'yes' or 'no'\n");
char reply[10];
scanf("%s", reply);

if(strcmp(reply, "yes") == 0){
  printf("\"Very well then, what would you like to say in your reply?\"\n");
  char input[200];
  char reply_mail[2000];
  scanf("%s", input);

  sprintf(reply_mail, "From: Sherlock Holmes <%s>\nTo: %s\nSubject: RE: %s\nContent: %s", email, strstr(mails[selection-1], "From:"), strstr(mails[selection-1], "Subject:"), input);
  
  printf("\n\"I have composed your email, Detective. Here is the final draft:\"\n\n");
  printf("%s\n", reply_mail);
}
else{
  printf("\"Very well, maybe another time. Goodbye %s!\"\n", email);
}

return 0;
}