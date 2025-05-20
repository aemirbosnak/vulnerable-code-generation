//FormAI DATASET v1.0 Category: Product Inventory System ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct product {
    int id;
    char name[20];
    float price;
    int quantity;
    struct product *next;
};

struct product *head=NULL;
struct product *tail=NULL;

//Add a product to the inventory
void add()
{
    int id, quantity;
    char name[20];
    float price;
    
    printf("Enter product id: ");
    scanf("%d",&id);
    printf("Enter product name: ");
    scanf("%s",name);
    printf("Enter product price: ");
    scanf("%f",&price);
    printf("Enter product quantity: ");
    scanf("%d",&quantity);
    
    struct product *new_node=(struct product*)malloc(sizeof(struct product));
    new_node->id=id;
    strcpy(new_node->name,name);
    new_node->price=price;
    new_node->quantity=quantity;
    new_node->next=NULL;
    
    if(head==NULL)
    {
        head=new_node;
        tail=new_node;
    }
    else
    {
        tail->next=new_node;
        tail=new_node;
    }
    printf("Product added successfully\n");
}

//Search a product by name
void search()
{
    char name[20];
    int found=0;
    printf("Enter the name of the product you want to search: ");
    scanf("%s",name);
    
    struct product *temp=head;
    
    while(temp!=NULL)
    {
        if(strcmp(temp->name,name)==0)
        {
            printf("Product id: %d\nProduct name: %s\nProduct price: %.2f\nProduct quantity: %d\n",temp->id,temp->name,temp->price,temp->quantity);
            found=1;
            break;
        }
        temp=temp->next;
    }
    if(found==0)
    {
        printf("Product not found\n");
    }
}

//Update the product details by id
void update()
{
    int id, choice;
    float price;
    int quantity;
    printf("Enter the id of the product you want to update: ");
    scanf("%d",&id);
    
    struct product *temp=head;
    
    while(temp!=NULL)
    {
        if(temp->id==id)
        {
            printf("What do you want to update?\n1. Price\n2. Quantity\nEnter your choice: ");
            scanf("%d",&choice);
            
            switch(choice)
            {
                case 1:
                    printf("Enter the new price: ");
                    scanf("%f",&price);
                    temp->price=price;
                    break;
                case 2:
                    printf("Enter the new quantity: ");
                    scanf("%d",&quantity);
                    temp->quantity=quantity;
                    break;
                default:
                    printf("Invalid choice\n");
            }
            printf("Product details updated successfully\n");
            return;
        }
        temp=temp->next;
    }
    printf("Product not found\n");
}

//Delete the product by id
void delete_node()
{
    int id;
    printf("Enter the id of the product you want to delete: ");
    scanf("%d",&id);
    
    struct product *temp1=head;
    struct product *temp2=NULL;
    
    while(temp1!=NULL)
    {
        if(temp1->id==id)
        {
            if(temp1==head)
            {
                head=temp1->next;
            }
            else if(temp1==tail)
            {
                temp2->next=NULL;
                tail=temp2;
            }
            else
            {
                temp2->next=temp1->next;
            }
            printf("Product deleted successfully\n");
            free(temp1);
            return;
        }
        temp2=temp1;
        temp1=temp1->next;
    }
    printf("Product not found\n");
}

//Display all the products in the inventory
void display()
{
    if(head==NULL)
    {
        printf("Inventory is empty\n");
        return;
    }
    struct product *temp=head;
    while(temp!=NULL)
    {
        printf("Product id: %d\nProduct name: %s\nProduct price: %.2f\nProduct quantity: %d\n\n",temp->id,temp->name,temp->price,temp->quantity);
        temp=temp->next;
    }
}

int main()
{
    int choice;
    while(1)
    {
        printf("Enter your choice:\n1. Add a product\n2. Search a product by name\n3. Update the product details by id\n4. Delete a product by id\n5. Display all the products\n6. Exit\n");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                add();
                break;
            case 2:
                search();
                break;
            case 3:
                update();
                break;
            case 4:
                delete_node();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}