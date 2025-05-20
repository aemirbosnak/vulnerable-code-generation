//FormAI DATASET v1.0 Category: String manipulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char juliet[50], romeo[50];
    printf("What light through yonder window breaks?\n");
    scanf("%s", juliet);
    printf("It is the east, and Juliet is the sun.\n");
   
    printf("Romeo, Romeo, wherefore art thou Romeo?\n");
    scanf("%s", romeo);
   
    if(strcmp(juliet, "Juliet") == 0) {
         printf("My bounty is as boundless as the sea,\n");
         printf("My love as deep; the more I give to thee,\n");
         printf("The more I have, for both are infinite.\n");   
    } else {
         printf("O Romeo, Romeo, wherefore art thou Romeo?\n");
         printf("Deny thy father and refuse thy name.\n");
         printf("Or if thou wilt not, be but sworn my love,\n");
         printf("And I'll no longer be a Capulet.\n");
    }

    int i, j;
    for(i = 0; juliet[i] != '\0'; i++) {
        if(isupper(juliet[i])){
            juliet[i] = tolower(juliet[i]);
        }
    }

    for(j = 0; romeo[j] != '\0'; j++) {
        if(islower(romeo[j])) {
            romeo[j] = toupper(romeo[j]);
        }
    }
   
    printf("My bounty is as boundless as the %s,\n", juliet);
    printf("My love as deep; the more I give to thee,\n");
    printf("The more I have, for both are infinite.\n");
   
    printf("But soft! What light through yonder window breaks?\n");
    printf("It is the east, and %s is the sun!\n", juliet);
   
    printf("My lips, two blushing pilgrims, ready stand\n");
    printf("To smooth that rough touch with a tender kiss.\n");
   
    printf("O, swear not by the moon, the inconstant moon,\n");
    printf("That monthly changes in her circle orb,\n");
    printf("Lest that thy love prove likewise variable.\n");
   
    printf("Good night, good night. Parting is such sweet sorrow,\n");
    printf("That I shall say good night till it be morrow.\n");

    return 0;
}