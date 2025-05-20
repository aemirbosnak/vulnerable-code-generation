//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<time.h>
#include<fcntl.h>
#include<time.h>
#include<sys/stat.h>
#include<errno.h>

// structure to store menu items
struct menu
{
    char item_name[30];
    int price;
    int quantity;
};

// function to read from menu file and store menu items in array of structures
void read_menu(struct menu m[])
{
    FILE *fp;
    char buff[255];
    int i = 0;
    fp = fopen("menu.txt", "r");
    if(fp == NULL)
    {
        printf("Error opening menu file.\n");
        exit(1);
    }
    while(fgets(buff, 255, (FILE*)fp))
    {
        sscanf(buff, "%s %d", m[i].item_name, &m[i].price);
        m[i].quantity = 0;
        i++;
    }
    fclose(fp);
}

// function to display menu items and their prices
void display_menu(struct menu m[])
{
    int i;
    printf("\n\n==========MENU==========\n\n");
    for(i = 0; m[i].price != 0; i++)
    {
        printf("%d. %-20s $%d\n", i+1, m[i].item_name, m[i].price);
    }
    printf("\n");
}

// function to take order from customer
void customer_order(struct menu m[], int q[])
{
    int i, choice, qty, total_price = 0;
    printf("Enter your order:\n");
    while(1)
    {
        printf("Item number (0 to exit): ");
        scanf("%d", &choice);
        if(choice == 0)
        {
            break;
        }
        printf("Quantity: ");
        scanf("%d", &qty);
        m[choice-1].quantity += qty;
        q[choice-1] += qty;
        total_price += qty * m[choice-1].price;
    }
    printf("\nTotal price: $%d\n", total_price);
}

// function to display the bill
void display_bill(struct menu m[], int q[])
{
    int i, total_price = 0;
    time_t now;
    struct tm *local;
    now = time(NULL);
    local = localtime(&now);
    int fd;
    fd = open("bill.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if(fd == -1)
    {
        printf("Error creating bill file.\n");
        exit(1);
    }
    char datetime[20];
    strftime(datetime, 20, "%m/%d/%Y %H:%M:%S", local);
    dprintf(fd, "\n\n==============BILL==============\n\n");
    dprintf(fd, "Date and time: %s\n\n", datetime);
    dprintf(fd, "%-20s %-10s %-10s %-10s\n", "Item name", "Price", "Quantity", "Total");
    for(i = 0; m[i].price != 0; i++)
    {
        if(m[i].quantity != 0)
        {
            dprintf(fd, "%-20s $%-9d %-10d $%-9d\n", m[i].item_name, m[i].price, m[i].quantity, (m[i].quantity * m[i].price));
            total_price += m[i].quantity * m[i].price;
        }
    }
    dprintf(fd, "\n%-43s $%d\n", "Total price", total_price);
    close(fd);
    printf("\nBill generated successfully!\n");
}

// main function
int main()
{
    struct menu m[30];
    int q[30] = {0};
    read_menu(m);
    display_menu(m);
    customer_order(m, q);
    display_bill(m, q);
    return 0;
}