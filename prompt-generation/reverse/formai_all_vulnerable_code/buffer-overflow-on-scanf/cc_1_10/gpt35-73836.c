//FormAI DATASET v1.0 Category: System administration ; Style: Romeo and Juliet
#include<stdio.h> 

// Declare the function for shutting down system by force

void shutDown() {
    printf("O Windows, Windows! wherefore art thou Windows?\n");
    printf("Deny thy kernel and refuse thy updates;\n");
    printf("Or if thou wilt not, be but sworn my admin\n");
    printf("And I’ll no longer be a user.\n");
    printf("‘Tis but thy update that is my enemy;\n");
    printf("Thou art thyself, though not a friend to me.\n");
    printf("What's Windows? It is nor OS, nor App,\n");
    printf("Nor mouse, nor keyboard, nor any other part\n");
    printf("Belonging to a PC. O, be some other name!\n");
    printf("What's in a name? That which we call a shutdown\n");
    printf("By any other word would smell as sweet;\n");
    printf("So shutdown would, were it not called shutdown\n");
    printf("Retain that dear exit which it owes\n");
    printf("Without that title. Shutdown, doff thy name,\n");
    printf("And for that name which is no part of thee\n");
    printf("Take all myself.\n");
}

int main()
{
    char setup[100];
    int current_user_id, root_id;
  
    printf("O! Setup.exe, Setup.exe! wherefore art thou Setup.exe?\n");
    printf("Deny thy install and refuse thy prompts;\n");
    printf("Or if thou wilt not, be but sworn my app\n");
    printf("And I'll no longer be a user.\n");
    printf("‘Tis but thy install that is my enemy;\n");
    printf("Thou art thyself, though not a friend to me.\n");
  
    printf("Enter thy password, brave admin.\n");
    scanf("%d",&root_id);

    // Check if admin account is authorized
    if(root_id == 12345) 
    {
        printf("I'm allowed! Now, I can install thee.");
        printf("\nHow dost thou want to be installed? Silently or quickly? ");
        scanf("%s", setup);
      
        if(strcmp(setup, "silently")==0)
        {
            printf("Hark, how silent doth thy install be!\n");
            printf("Installing thee right now...\n");
            // Installing silently here
            printf("Installed! Go and thy software check.\n");
        }

        else if(strcmp(setup, "quickly")==0)
        {
            printf("Quickly? Yea, I shall install thee hastily.\n");
            printf("Quickening the install...\n");
            // Installing quickly here
            printf("Installed! Go and thy software enjoy.\n");
        }

        else 
        {
            printf("What! Art thou a script kiddie?\n");
            printf("Never tried that on me, young one! Access denied.\n");
            shutDown(); // Forceful shutdown
        }
    }
    
    else
    {
        printf("Thou art not authorized to install me!\n");
        printf("Hark! What light through yonder Windows breaks.\n");
        printf("Restart and try again!\n");
        shutDown(); // Forceful shutdown
    }
  
    return 0;
}