//FormAI DATASET v1.0 Category: Smart home light control ; Style: decentralized
#include<stdio.h>//standard input output header file
#include<stdlib.h>//header file for dynamic memory allocation functions
#include<string.h>//header file for string manipulation functions

struct light//structure definition for light
{
    char name[20];
    int status;
};

typedef struct light Light;//using typedef to simplify the structure name

void controlLight(Light* ptr);//function prototype for controlling the light
void toggle(Light* ptr);//function prototype for toggling the light

int main()
{
    int n;//variable to store the number of lights
    printf("Enter the number of lights: ");
    scanf("%d",&n);
    getchar();//to handle buffer

    Light* lightArray = (Light*)malloc(n*sizeof(Light));//dynamically allocating memory for the light array
    for(int i=0;i<n;i++)
    {
        printf("Enter name of light %d: ",i+1);
        fgets(lightArray[i].name,20,stdin);//getting the name of the light
        lightArray[i].name[strcspn(lightArray[i].name, "\n")] = 0;//removing the newline character
        lightArray[i].status=0;//initializing the status of light to 'off'
    }

    int choice;
    while(1)
    {
        //menu display for controlling the lights
        printf("1. Control Light\n");
        printf("2. Toggle Light\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        getchar();//to handle buffer

        switch(choice)
        {
            case 1:
                controlLight(lightArray);//calling function to control the light
                break;

            case 2:
                toggle(lightArray);//calling function to toggle the light
                break;

            case 3:
                free(lightArray);//deallocating the dynamically allocated memory
                exit(0);//exiting the program
                break;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void controlLight(Light* ptr)
{
    char name[20];
    printf("Enter the name of light: ");
    fgets(name,20,stdin);//getting the name of the light
    name[strcspn(name, "\n")] = 0;//removing the newline character

    int found=0;
    for(int i=0;i<sizeof(ptr)/sizeof(Light);i++)
    {
        if(strcmp(ptr[i].name,name)==0)//comparing the input name with the name in the array
        {
            found=1;
            printf("Enter the status of light(%s): ",name);
            scanf("%d",&ptr[i].status);//getting the status of the light
            getchar();//to handle buffer
            printf("Light(%s) is now %s\n",name,(ptr[i].status==0)?"off":"on");//displaying the status of the light
            break;
        }
    }
    if(!found)
    {
        printf("Light(%s) not found!\n",name);//if the input name is not found, display error message
    }
}

void toggle(Light* ptr)
{
    char name[20];
    printf("Enter the name of light to toggle: ");
    fgets(name,20,stdin);//getting the name of the light
    name[strcspn(name, "\n")] = 0;//removing the newline character

    int found=0;
    for(int i=0;i<sizeof(ptr)/sizeof(Light);i++)
    {
        if(strcmp(ptr[i].name,name)==0)//comparing the input name with the name in the array
        {
            found=1;
            ptr[i].status=(ptr[i].status==0)?1:0;//toggling the status of the light
            printf("Light(%s) is now %s\n",name,(ptr[i].status==0)?"off":"on");//displaying the status of the light
            break;
        }
    }
    if(!found)
    {
        printf("Light(%s) not found!\n",name);//if the input name is not found, display error message
    }
}