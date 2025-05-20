//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Romeo and Juliet
#include<stdio.h>

int main()
{
    // These user inputs represent Romeo's personal finance information.
    float romeo_income, romeo_savings, romeo_expenses;
    printf("O Romeo, please tell me your monthly income: \n");
    scanf("%f", &romeo_income);
    printf("Ah, and your current savings: \n");
    scanf("%f", &romeo_savings);
    printf("And lastly, your monthly expenses: \n");
    scanf("%f", &romeo_expenses);
    
    // These user inputs represent Juliet's personal finance information.
    float juliet_income, juliet_savings, juliet_expenses;
    printf("My dear Juliet, what is your monthly income: \n");
    scanf("%f", &juliet_income);
    printf("And your current savings: \n");
    scanf("%f", &juliet_savings);
    printf("And lastly, your monthly expenses: \n");
    scanf("%f", &juliet_expenses);
    
    // Romeo and Juliet come from very different financial situations. 
    // Romeo earns more than Juliet, and has more savings.
    // They both need to know if they can afford to live together.
    
    float total_income = romeo_income + juliet_income;
    float total_expenses = romeo_expenses + juliet_expenses;
    float total_savings = romeo_savings + juliet_savings;
    float total_savings_needed = total_expenses * 3;
    
    // Romeo and Juliet need to know if they have enough savings to cover living expenses for three months.
    if (total_savings >= total_savings_needed) {
        printf("O Romeo and Juliet! Thou art well prepared financially to live together.\n");
    } else {
        printf("Alas, O Romeo and Juliet! Thou art not yet prepared financially to live together. Thou shouldst save more.\n");
    }
    
    // Romeo and Juliet need to know if they have any surplus or if they need to cut back on expenses.
    float total_surplus = total_income - total_expenses;
    if (total_surplus > 0) {
        printf("O sweet Romeo and Juliet! Ye have a monthly surplus of %.2f. Thou may live comfortably.\n", total_surplus);
    } else if (total_surplus < 0) {
        printf("Alack, O Romeo and Juliet! Ye have a monthly deficit of %.2f. Thou will need to cut back on expenses.\n", -total_surplus); 
    } else {
        printf("O Romeo and Juliet! Ye have no surplus nor deficit. Thou hast a zero-sum game.\n");
    }
    
    return 0;
}